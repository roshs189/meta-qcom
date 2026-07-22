DESCRIPTION = "CDT (Configuration Data Table) Firmware for Qualcomm Nord platform"

SRC_URI = " \
    https://artifactory-las.qualcomm.com/artifactory/lint-lv-local/nord-test/NORD_RIDESX_CDT.zip;name=nord-ridesx-cdt \
    "
SRC_URI[nord-ridesx-cdt.sha256sum] = "645f21677f27f6c2ca897183ef8a5a82e2181ba83e4e6cf06a07e45906130a9e"

QCOM_CDT_SUBDIR = "nord"

include firmware-qcom-cdt-common.inc
