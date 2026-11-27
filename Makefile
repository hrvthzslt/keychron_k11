.DEFAULT_GOAL := help

keychron_path := $(HOME)/qmk_firmware_keychron
QMK ?= qmk

help:
	@grep -h -E '^[a-zA-Z0-9_-]+:.*?# .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?# "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

install: # Install and setup keychron qmk repo
	-git clone -b wireless_playground https://github.com/Keychron/qmk_firmware.git $(keychron_path)
	-cd $(keychron_path) && git remote add upstream https://github.com/qmk/qmk_firmware.git
	-cd $(keychron_path) && make git-submodule
	@echo "Setting up QMK firmware dependencies..."
	$(QMK) setup -H "$(keychron_path)"

k11-compile: # Compile custom keychron k11 max ansi encoder rgb layout
	$(QMK) config user.qmk_home=$(keychron_path)
	$(QMK) userspace-add -kb keychron/k11_max/ansi_encoder/rgb -km hrvthzslt
	$(QMK) compile -kb keychron/k11_max/ansi_encoder/rgb -km hrvthzslt

k11-flash: # Flash custom keychron k11 max ansi encoder rgb layout
	$(QMK) config user.qmk_home=$(keychron_path)
	$(QMK) userspace-add -kb keychron/k11_max/ansi_encoder/rgb -km hrvthzslt
	$(QMK) flash -kb keychron/k11_max/ansi_encoder/rgb -km hrvthzslt
