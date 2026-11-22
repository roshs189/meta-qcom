require trusted-firmware-a-qcom.inc

DEPENDS += "optee-os-qcom-nord"

SRC_URI += " \
    file://0001-feat-qti-accesscontrol-add-xpu4-hardware-driver.patch \
    file://0002-feat-qti-accesscontrol-add-runtime-config-image-read.patch \
    file://0003-build-qti-accesscontrol-add-xpu_version-selector-and.patch \
    file://0004-feat-qti-nord-enable-access-control-driver.patch \
    file://0005-fix-qti-take-the-SPMI-arbiter-base-from-the-SoC-defi.patch \
    file://0006-refactor-qti-rename-PMIC_ARB_BASE-to-QTI_PMIC_ARB_BA.patch \
    file://0007-fix-qti-configure-Shikra-PS_HOLD.patch \
    file://0008-fix-qti-use-a-PMIC-hard-reset-for-SYSTEM_RESET.patch \
    file://0009-feat-qti-add-SAIL-communication-for-resets.patch \
    file://0010-plat-qti-update-PMIC-configs-for-PSCI-reset-shutdown.patch \
    file://0011-feat-qti-enable-nord-RPMh-and-CMD-DB-support.patch \
    file://0012-feat-qti-add-nord-clock-driver.patch \
    file://0013-feat-qti-add-secure-HSR-SMMU-support.patch \
    file://0014-feat-qti-add-PSCI-SYSTEM_RESET2-support.patch \
    file://0015-feat-qti-extend-reboot-reason-cookie-stash-to-lemans.patch \
    file://0016-feat-qti-log-SYSTEM_RESET2-parameters.patch \
    file://0017-feat-qti-enable-PSCI-SYSTEM_RESET2-support-for-nord.patch \
    file://0018-fix-qti-notify-SAIL-on-vendor-warm-reset-too.patch \
    file://0019-fix-qti-make-warm-reset-SAIL-check-explicit-in-qti_s.patch \
"

TFA_PLATFORM = "nord"
FIP_ELF_ADDR = "0xaf000000"
