DESCRIPTION = "QCOM NHLOS Firmware for Qualcomm Nord platform"
LICENSE = "LICENSE.qcom-2"
# FIXME: placeholder md5sum - board-spec has no verified license hash for
# this board yet. Replace with the real md5 of LICENSE.qcom-2.txt once the
# NORD_bootbinaries.zip contents can be inspected/hashed.
LIC_FILES_CHKSUM = "file://${UNPACKDIR}/${BOOTBINARIES}/LICENSE.qcom-2.txt;md5=00000000000000000000000000000000"

FW_ARTIFACTORY = "artifactory-las.qualcomm.com/artifactory/lint-lv-local/nord-test"
BOOTBINARIES = "NORD_bootbinaries"

SRC_URI = " \
    https://${FW_ARTIFACTORY}/${BOOTBINARIES}.zip;name=bootbinaries \
    "

QCOM_BOOT_IMG_SUBDIR = "nord"

include firmware-qcom-boot-common.inc
