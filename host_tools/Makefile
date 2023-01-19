
# function to check required arguments
check_defined = \
	$(strip $(foreach 1,$1, \
		$(call __check_defined,$1)))
__check_defined = \
	$(if $(value $1),, \
		$(error Undefined $1))

# if all of the host tools are python scripts, we only need to copy them into the volume
all:
	$(call check_defined TOOLS_OUT_DIR)
	cp unlock_tool ${TOOLS_OUT_DIR}/unlock_tool
	cp pair_tool ${TOOLS_OUT_DIR}/pair_tool
	cp enable_tool ${TOOLS_OUT_DIR}/enable_tool
	cp package_tool ${TOOLS_OUT_DIR}/package_tool
