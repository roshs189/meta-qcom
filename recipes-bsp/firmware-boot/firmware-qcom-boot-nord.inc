DESCRIPTION = "QCOM NHLOS Firmware for Qualcomm Nord platform"
LICENSE = "LicenseRef-LICENSE.qcom-2"
# §4a live-bundle-wins: the single Nord_bootbinaries.zip ships no LICENSE.qcom-2 —
# it carries license.bin (md5 computed live from the fetched zip). The pinned
# LICENSE.qcom-2/165287… guess was from the OLD two-zip bundle and would point at
# a nonexistent file. LICENSE identifier below stays LicenseRef-LICENSE.qcom-2
# (covered by INCOMPATIBLE_LICENSE_EXCEPTIONS); only the checksum file/md5 change.
LIC_FILES_CHKSUM = "file://${UNPACKDIR}/${BOOTBINARIES}/license.bin;md5=675a095e5cf03c58c6c812b32cec6b9d"

# Single literal .zip from artifactory-np — mirrors the spec's
# firmware_boot.fw_artifactory (scheme + .zip suffix). Per SKILL.md Section 4's
# `case "$FW" in *.zip)` branch this URL is used VERBATIM as the SRC_URI; no
# basename is reconstructed from ${BOOTBINARIES}/${PV}. BOOTBINARIES still names
# the internal unpack dir (Nord_bootbinaries/, drives S / LIC_FILES_CHKSUM /
# do_deploy); PV is recipe-version bookkeeping only (firmware-qcom-boot-nord_00002.bb).
# No immutable companion in single-zip form, so a single SRC_URI, no
# do_deploy:append. NOTE: the prior two-zip bundle's immutable companion carried
# 13 boot binaries deployed into this same nord/ subdir — the single zip must
# contain all of them or the flat build loses them silently (spec firmware_boot.notes).
# §4a live-bundle-wins: the single Nord_bootbinaries.zip unpacks to a top-level
# dir "Nord_bootbinaries/" (capital N only) — NOT the all-caps NORD_bootbinaries
# the old two-zip bundle used. On case-sensitive Linux S must match the real dir
# or do_unpack/S resolves to a nonexistent path and deploy ships nothing.
BOOTBINARIES = "Nord_bootbinaries"

SRC_URI = " \
    https://artifactory-np.qualcomm.com:443/artifactory/lecoreqipl-oracle-rpm-hyd-fed/0001/Nord_bootbinaries.zip;name=bootbinaries \
    "

QCOM_BOOT_IMG_SUBDIR = "nord"

include firmware-qcom-boot-common.inc
