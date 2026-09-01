DESCRIPTION = "QCOM NHLOS Firmware for Qualcomm Nord platform"
LICENSE = "LicenseRef-LICENSE.qcom-2"
LIC_FILES_CHKSUM = "file://${UNPACKDIR}/${BOOTBINARIES}/LICENSE.qcom-2;md5=165287851294f2fb8ac8cbc5e24b02b0"

# Nexus release dir (no scheme, no .zip) — mirrors the spec's
# firmware_boot.fw_artifactory. Both zip basenames are reconstructed from
# ${BOOTBINARIES}/${PV} below.
FW_ARTIFACTORY = "softwarecenter.qualcomm.com/nexus/generic/product/chip/tech-package/Nord_bootbinaries.1.0/nord_bootbinaries.1.0-test-device-public"
BOOTBINARIES = "NORD_bootbinaries"

# Two zips under the single versioned dir: plain (unpacks to
# NORD_bootbinaries/, drives S / LIC_FILES_CHKSUM / base do_deploy) and the
# immutable companion (unpacks to NORD_bootbinaries_immutable/, deployed by the
# do_deploy:append() below). See the spec firmware_boot.notes.
SRC_URI = " \
    https://${FW_ARTIFACTORY}/${PV}/${BOOTBINARIES}_${PV}.zip;name=bootbinaries \
    https://${FW_ARTIFACTORY}/${PV}/${BOOTBINARIES}_immutable_${PV}.zip;name=bootbinaries_immutable \
    "

QCOM_BOOT_IMG_SUBDIR = "nord"

include firmware-qcom-boot-common.inc

# Deploy the immutable companion set into the SAME ${QCOM_BOOT_IMG_SUBDIR}.
# The immutable set is 13 arbitrary boot binaries (not a fixed manifest), so we
# reuse the plain zip's extension-glob set verbatim and strip gpt_*/zeros_* just
# like the base do_deploy(). Plain vs immutable are disjoint except LICENSE.qcom-2
# and Readme.txt (neither globbed), so no deploy overwrite occurs.
do_deploy:append() {
    IMMUT="${UNPACKDIR}/${BOOTBINARIES}_immutable"
    if [ -d "${IMMUT}" ]; then
        install -d ${DEPLOYDIR}/${QCOM_BOOT_IMG_SUBDIR}
        find "${IMMUT}" -maxdepth 1 -name 'gpt_*.bin'   -delete
        find "${IMMUT}" -maxdepth 1 -name 'zeros_*.bin' -delete
        for ext in bin elf fv lzma mbn melf xz; do
            find "${IMMUT}" -maxdepth 1 -name "*.${ext}" \
                -exec install -m 0644 {} ${DEPLOYDIR}/${QCOM_BOOT_IMG_SUBDIR} \;
        done
        find "${IMMUT}" -maxdepth 1 -name 'qsahara_*.xml' \
            -exec install -m 0644 {} ${DEPLOYDIR}/${QCOM_BOOT_IMG_SUBDIR} \;
    fi
}
