############################################################################### 
# File Name  : E2E_cfg.mak 
# Description: Configuration makefile 
#------------------------------------------------------------------------------
# COPYRIGHT
#------------------------------------------------------------------------------
# Copyright (c) 2019 by Vector Informatik GmbH.  All rights reserved.
#------------------------------------------------------------------------------
# REVISION HISTORY
#------------------------------------------------------------------------------
# Refer to the E2E_rules.mak file.
############################################################################### 

###############################################################
# Use PROFIL1
#
# Possible Values:
# 0 - No PROFIL1 used
# 1 - PROFIL1 used
###############################################################
# E2E_USE_PROFIL1 = 0

###############################################################
# Use PROFIL2
#
# Possible Values:
# 0 - No PROFIL2 used
# 1 - PROFIL2 used
###############################################################
# E2E_USE_PROFIL2 = 0

###############################################################
# Use PROFIL4
#
# Possible Values:
# 0 - No PROFIL4 used
# 1 - PROFIL4 used
###############################################################
# E2E_USE_PROFIL4 = 0

###############################################################
# Use PROFIL5
#
# Possible Values:
# 0 - No PROFIL5 used
# 1 - PROFIL5 used
###############################################################
# E2E_USE_PROFIL5 = 0

###############################################################
# Use PROFIL6
#
# Possible Values:
# 0 - No PROFIL6 used
# 1 - PROFIL6 used
###############################################################
# E2E_USE_PROFIL6 = 0

###############################################################
# Use PROFIL7
#
# Possible Values:
# 0 - No PROFIL7 used
# 1 - PROFIL7 used
###############################################################
# E2E_USE_PROFIL7 = 0

###############################################################
# Use PROFILJLR
#
# Possible Values:
# 0 - No PROFILJLR used
# 1 - PROFILJLR used
###############################################################
# E2E_USE_PROFILJLR = 0

##############################################################
# E2E_CONFIG_PATH: (not used for Vector)
# The Variable E2E_CONFIG_PATH is optional. It allows the
# configuration of the directory, where you can also find the
# generated source files. Generally they should be in the
# directory $(PROJECT_ROOT)\source\networks.
# But if the application should run on several hardware
# targets, then different E2E configurations of different
# directories will be necessary. Therefore the variable
# E2E_CONFIG_PATH should be used.
#
# For example:
# E2E_CONFIG_PATH = $(PROJECT_ROOT)\source\network\v850
# E2E_CONFIG_PATH = $(PROJECT_ROOT)\source\network\st10
# E2E_CONFIG_PATH = $(PROJECT_ROOT)\source\network\v850
#

#E2E_CONFIG_PATH =


##############################################################
# E2E_DRIVER_MODE:  (not used for Vector)
# Not relevant for module E2E, leave it as it is.
#
# For example:
# E2E_DRIVER_MODE = singlechannel/multichannel
#

#E2E_DRIVER_MODE = singlechannel


###############################################################
# REQUIRED
#
# No Other resources are required to write a Configuration
# Makefile.
#
###############################################################


###############################################################
# PROVIDE
#
# A Configuration Makefile does not provide resources for other
# basic software bundles or the base_make package
#
###############################################################


###############################################################
# REGISTRY
#
# Like the Provide-Section this block is empty.
#
###############################################################


###############################################################
# SPECIFIC
#
# All variables in the _cfg makefile are "Specific" variables,
# because they should only be used in the *_check.mak,
# *_defs.mak and *_rules.mak Makefiles of the same basic
# software bundle.
###############################################################
