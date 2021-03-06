#!/bin/sh
#
# generated.sh - shell script fragment - not very useful on its own
#
# Machine generated for a CPU named "cpu" as defined in:
# e:\Altera\80\kits\cycloneIII_3c120_dev\examples\cycloneIII_3c120_dev_niosII_standard\software\hello_ucosii_0_syslib\..\..\cycloneIII_3c120_dev_niosII_standard_sopc.ptf
#
# Generated: 2015-11-10 20:33:39.781

# DO NOT MODIFY THIS FILE
#
#   Changing this file will have subtle consequences
#   which will almost certainly lead to a nonfunctioning
#   system. If you do modify this file, be aware that your
#   changes will be overwritten and lost when this file
#   is generated again.
#
# DO NOT MODIFY THIS FILE

# This variable indicates where the PTF file for this design is located
ptf=e:\Altera\80\kits\cycloneIII_3c120_dev\examples\cycloneIII_3c120_dev_niosII_standard\software\hello_ucosii_0_syslib\..\..\cycloneIII_3c120_dev_niosII_standard_sopc.ptf

# This variable indicates whether there is a CPU debug core
nios2_debug_core=yes

# This variable indicates how to connect to the CPU debug core
nios2_instance=0

# This variable indicates the CPU module name
nios2_cpu_name=cpu

# These variables indicate what the System ID peripheral should hold
sidp=0x0c021090
id=712662328u
timestamp=1219701055u

# Include operating system specific parameters, if they are supplied.

if test -f /cygdrive/c/altera/12.0sp2/nios2eds/components/micrium_uc_osii/build/os.sh ; then
   . /cygdrive/c/altera/12.0sp2/nios2eds/components/micrium_uc_osii/build/os.sh
fi
