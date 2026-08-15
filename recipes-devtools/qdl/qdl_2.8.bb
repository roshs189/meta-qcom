SUMMARY = "Qualcomm Download Tool"
DESCRIPTION = "Userspace tool to flash images to Qualcomm SoCs over the \
EDL (Emergency Download) USB protocol"

HOMEPAGE = "https://github.com/linux-msm/qdl"
LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://LICENSE;md5=da6bfde9cb5bc5120a51775381f6edf1"

SRC_URI = " \
    git://github.com/linux-msm/qdl.git;protocol=https;branch=master;tag=v${PV} \
    file://0001-meson-make-zip-container-support-optional.patch \
"
SRCREV = "ced92634a8e4f0681cd1137c5bba079b23479c44"

DEPENDS = "libusb1 libxml2"

inherit meson pkgconfig

# Zip-container support -- flashing directly from a zip archive carrying
# the flash description inside and the create-zip subcommand -- is the
# only feature that pulls in libzip, which lives in meta-openembedded
# rather than oe-core.  Keep it off by default so this recipe stays
# self-contained in oe-core.
PACKAGECONFIG ?= ""
PACKAGECONFIG[zip] = "-Dzip-container=enabled,-Dzip-container=disabled,libzip"

BBCLASSEXTEND = "native nativesdk"
