#  2023 eCTF
#  Deployment Makefile
#  Kyle Scaplen
#
#  (c) 2023 The MITRE Corporation
#
# This source file is part of an example system for MITRE's 2023 Embedded System CTF (eCTF).
# This code is being provided only for educational purposes for the 2023 MITRE eCTF competition,
# and may not meet MITRE standards for quality. Use this code at your own risk!

# function to check required arguments
check_defined = \
	$(strip $(foreach 1,$1, \
		$(call __check_defined,$1)))
__check_defined = \
	$(if $(value $1),, \
		$(error Undefined $1))

all:
	$(call check_defined SECRETS_DIR)
	echo "SECRET!" > ${SECRETS_DIR}/global_secrets.txt
