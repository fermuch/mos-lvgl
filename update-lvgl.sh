#!/bin/bash
set -euxo pipefail

git subtree pull --prefix vendor/lvgl https://github.com/lvgl/lvgl.git release/v8.3 --squash
