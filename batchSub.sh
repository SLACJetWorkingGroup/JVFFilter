#!/bin/bash

[ "$USER" == "pnef" ]     && WorkDir=/u/at/pnef/Work/Code/TruthJets/JVFFilter/ && DataDir=//u/at/pnef/nfs/Data/JVFFilter/

# add similar line if you are not pnef

SubFileLoc=`pwd`/_batchSingleSub.sh
#rm $SubFileLoc
DateSuffix=`date +%Y%m%d_%Hh%Mmin`

echo '#!/bin/bash
echo CD to $1
echo CMD is $2

cd $1
source setup.sh
cmd=$4

echo MAKING TEMP DIR $2
JOBFILEDIR=$2
mkdir $JOBFILEDIR
REALOUT=$3
echo MADE TEMP DIR $JOBFILEDIR
echo WILL COPY TO $REALOUT

shift
shift
echo Calling $cmd $*
$cmd $*
cp -r $JOBFILEDIR/*.root $REALOUT
echo COPYING to $REALOUT
rm -rf $JOBFILEDIR
' > $SubFileLoc
chmod u+x $SubFileLoc

#----------------
for mu in 0 20 50 100; do
    Queue=long
    nevents=1000
    njobs=10
    LogPrefix=`pwd`/logs/${DateSuffix}/${DateSuffix}_bsub_${mu}_
    OutDirFinal=${DataDir}/${DateSuffix}
    mkdir -p `dirname $LogPrefix`
    mkdir -p $OutDirFinal
    echo
    echo "Submitting $njobs jobs each with $nevents events to $Queue"
    echo $LogPrefix
    for (( ii=1; ii<=$njobs; ii++ )) ;  do
        echo $ii
        OutDir=/scratch/${DateSuffix}_${ii}/
        bsub -q ${Queue} -R rhel60 -o $LogPrefix${ii}.log $SubFileLoc           \
            ${WorkDir} ${OutDir} ${OutDirFinal} ./TruthJets.exe  \
            --nPU $mu                 \
            --OutFile ${OutDir}/Sample_mu_${mu}_nevents_${nevents}_job_${ii}_Process.root \
            --NEvents ${nevents} 

    
    done
done

