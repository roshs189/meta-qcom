DESCRIPTION = "QCOM NHLOS Firmware for Qualcomm Nord platform"
LICENSE = "LicenseRef-LICENSE.qcom-2"
LIC_FILES_CHKSUM = "file://${UNPACKDIR}/${BOOTBINARIES}/LICENSE.qcom-2;md5=165287851294f2fb8ac8cbc5e24b02b0"

BOOTBINARIES = "NORD_bootbinaries"

# Flat, date-stamped bundle on artifactory-las: no ${PV} subdir and no
# NORD_bootbinaries_${PV} basename, so the URL is taken verbatim from the
# spec's firmware_boot.fw_artifactory rather than reconstructed. It still
# unpacks into NORD_bootbinaries/ (drives S / LIC_FILES_CHKSUM / deploy).
SRC_URI = " \
    https://artifactory-las.qualcomm.com/artifactory/lint-lv-local/firmware-artifacts/nord-bootbinaries-20150730.zip;name=bootbinaries \
    "

QCOM_BOOT_IMG_SUBDIR = "nord"

include firmware-qcom-boot-common.inc
