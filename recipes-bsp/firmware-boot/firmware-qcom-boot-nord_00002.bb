require firmware-qcom-boot-nord.inc

# SINGLE-ZIP FORM: one SRC_URI (name=bootbinaries), no immutable companion.
#
# sha256 computed LIVE (§4a) from the fetched single Nord_bootbinaries.zip
# (artifactory-np.qualcomm.com, 30203177 bytes). This is the real checksum of the
# new single bundle — NOT the stale old two-zip plain-bundle value. If the bundle
# is ever re-published, qcom-yocto-build-heal recomputes this live and wins.
SRC_URI[bootbinaries.sha256sum] = "39a5e9d4047654a0bad8f79014cee1533754817cfae65214e4d2927aa1d14c13"
