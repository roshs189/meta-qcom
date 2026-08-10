DESCRIPTION = "QCOM NHLOS Firmware for Qualcomm NORD platform"
LICENSE = "LICENSE.qcom-2"
LIC_FILES_CHKSUM = "file://${UNPACKDIR}/${BOOTBINARIES}/LICENSE.qcom-2;md5=165287851294f2fb8ac8cbc5e24b02b0"

# License file inside NORD_bootbinaries.zip is named LICENSE.qcom-2 (no .txt
# extension); LIC_FILES_CHKSUM must point at
# file://${UNPACKDIR}/${BOOTBINARIES}/LICENSE.qcom-2, not LICENSE.qcom-2.txt.
FW_ARTIFACTORY = "artifactory-las.qualcomm.com/artifactory/lint-lv-local/nord-test"
BOOTBINARIES = "NORD_bootbinaries"

SRC_URI = " \
    https://${FW_ARTIFACTORY}/${BOOTBINARIES}.zip;name=bootbinaries \
    "

QCOM_BOOT_IMG_SUBDIR = "nord"

include firmware-qcom-boot-common.inc
