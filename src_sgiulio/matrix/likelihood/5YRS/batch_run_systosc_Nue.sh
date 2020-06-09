#!/bin/sh -f
#
#    Job name (default is name of pbs script file)
#PBS -N systosc_Nue
#
#PBS -l mem=16GB
#    Resource limits: max. wall clock time during which job can be running
#PBS -l walltime=18:00:00
#
#          The directive below directs that the standard output and
#          error streams are to be merged, intermixed, as standard
#          output. 
#PBS -j oe
#PBS -o /storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/matrix/likelihood/5YRS/logs/batch_systosc_Nue.txt
#
##########################################

echo ------------------------------------------------------
echo 'Job is running on node(s): '
cat \$PBS_NODEFILE
echo ------------------------------------------------------
echo PBS: qsub is running on \$PBS_O_HOST
echo PBS: executing queue is \$PBS_QUEUE
echo PBS: execution mode is \$PBS_ENVIRONMENT
echo PBS: job identifier is \$PBS_JOBID
echo PBS: job name is \$PBS_JOBNAME
echo PBS: current home directory is \$PBS_O_HOME
echo PBS: PATH = \$PBS_O_PATH
echo ------------------------------------------------------

# COMMAND to EXECUTE:

source /storage/local/exp_soft/juno/root-6.12.06/root-6.12.06-install/bin/thisroot.sh
cd /storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/matrix/likelihood/5YRS
time ./run_systosc_Nue.sh > logs/log_systosc_Nue.txt 2>&1

exit
