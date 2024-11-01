#! /bin/bash

# From https://stackoverflow.com/a/246128
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
cd $SCRIPT_DIR/..

export GZ_SIM_RESOURCE_PATH=${PWD}/simulation-descriptions/models
echo $GZ_SIM_RESOURCE_PATH

gz sim simulation-descriptions/world.sdf
