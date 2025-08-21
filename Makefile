.DEFAULT_GOAL := help

keychron_path := $(HOME)/qmk_firmware_keychron
venv_path := $(keychron_path)/venv
venv_activate := . $(venv_path)/bin/activate

help:
	@grep -h -E '^[a-zA-Z0-9_-]+:.*?# .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?# "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

setup-venv: # Setup Python virtual environment for QMK
	/usr/bin/python3 -m venv $(venv_path)
	$(venv_activate) && pip install -r $(keychron_path)/requirements.txt

install: # Install and setup keychron qmk repo
	-git clone -b wireless_playground https://github.com/Keychron/qmk_firmware.git $(keychron_path)
	-cd $(keychron_path) && git remote add upstream https://github.com/qmk/qmk_firmware.git
	@echo "Setting up Python virtual environment for QMK..."
	qmk setup
	@$(MAKE) setup-venv

k11-compile: # Compile custom keychron k11 max ansi encoder rgb layout
	$(venv_activate) && qmk config user.qmk_home=$(keychron_path)
	$(venv_activate) && qmk userspace-add -kb keychron/k11_max/ansi_encoder/rgb -km hrvthzslt
	$(venv_activate) && qmk compile -kb keychron/k11_max/ansi_encoder/rgb -km hrvthzslt

k11-flash: # Flash custom keychron k11 max ansi encoder rgb layout
	$(venv_activate) && qmk config user.qmk_home=$(keychron_path)
	$(venv_activate) && qmk userspace-add -kb keychron/k11_max/ansi_encoder/rgb -km hrvthzslt
	$(venv_activate) && qmk flash -kb keychron/k11_max/ansi_encoder/rgb -km hrvthzslt
