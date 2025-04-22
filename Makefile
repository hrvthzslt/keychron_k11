.DEFAULT_GOAL := help

keychron_path := $(HOME)/qmk_firmware_keychron

help:
	@grep -h -E '^[a-zA-Z0-9_-]+:.*?# .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?# "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

install: # Install and setup keychron qmk repo
	-git clone -b wireless_playground https://github.com/Keychron/qmk_firmware.git $(keychron_path)
	-cd $(keychron_path) && git remote add upstream https://github.com/qmk/qmk_firmware.git
	qmk config user.qmk_home=$(keychron_path)
	qmk setup

k11-compile: # Compile custom keychron k11 max ansi encoder rgb layout
	qmk config user.qmk_home=$(keychron_path)
	qmk userspace-add -kb keychron/k11_max/ansi_encoder/rgb -km hrvthzslt
	qmk compile -kb keychron/k11_max/ansi_encoder/rgb -km hrvthzslt
