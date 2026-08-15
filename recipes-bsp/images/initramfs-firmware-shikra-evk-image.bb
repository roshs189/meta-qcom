DESCRIPTION = "Tiny ramdisk image with Shikra EVK firmware files"

PACKAGE_INSTALL += " \
    packagegroup-shikra-evk-firmware \
"

require initramfs-firmware-image.inc
