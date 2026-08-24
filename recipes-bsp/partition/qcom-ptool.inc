HOMEPAGE = "https://github.com/qualcomm-linux/qcom-ptool"
LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://LICENSE;md5=b0a8acd90d872086b279ead88af03369"

SRC_URI = "git://github.com/roshs189/qcom-ptool.git;protocol=https;nobranch=1"
SRCREV = "95db71b79dcbd44ad51998bfddb48add489a1965"

# The pinned qcom-ptool source ships a pyproject.toml that declares the
# [tool.pytest.ini_options] table twice, which is invalid TOML and makes
# pyproject-build (python_pep517 do_compile) abort with
# "Cannot declare ('tool','pytest','ini_options') twice". Drop the second,
# duplicate table before the wheel build. Idempotent: once only one table
# remains this awk rewrites the file unchanged.
do_compile:prepend() {
    if [ -f "${S}/pyproject.toml" ]; then
        awk '
            /^\[tool\.pytest\.ini_options\]/ { c++; if (c > 1) { skip=1; next } }
            skip && /^\[/ { skip=0 }
            skip { next }
            { print }
        ' "${S}/pyproject.toml" > "${S}/pyproject.toml.dedup"
        mv "${S}/pyproject.toml.dedup" "${S}/pyproject.toml"
    fi
}
