DESCRIPTION = "Webkit browser for HbbTV"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
#require conf/license/license-close.inc

PV = "1.1"
PR = "${SRCDATE}"
SRC_URI = "http://archive.vuplus.com/download/build_support/webkit-hbbtv-browser_${MACHINE}_${SRCDATE}.tar.gz"

RDEPENDS_${PN} = "libudev"

do_install_append() {
	install -d ${D}${bindir}
	install -d ${D}${libdir}/mozilla/plugins
	install -d ${D}/home/root

	install -m 0755 ${WORKDIR}/webkit-hbbtv-browser/none.html ${D}/home/root
	install -m 0755 ${WORKDIR}/webkit-hbbtv-browser/browser ${D}${bindir}
	install -m 0755 ${WORKDIR}/webkit-hbbtv-browser/libhbbtvplugin.so ${D}${libdir}/mozilla/plugins/

	# patch browser for libudev.so.1
	sed -i 's/libudev.so.0/libudev.so.1/g' ${D}${bindir}/browser
}

do_package_qa() {
}

#pkg_postinst_${PN} () {
#	if [ -z "$D" ]; then
#		if [ ! -f /lib/libudev.so.0 ]; then
#			ln -s /lib/libudev.so.1 /lib/libudev.so.0
#		fi
#	fi
#}

PROVIDES += "webkit-hbbtv-browser"
RPROVIDES_${PN} += "webkit-hbbtv-browser"

PACKAGE_ARCH := "${MACHINE_ARCH}"

FILES_${PN} = "/"

INSANE_SKIP_${PN} += "already-stripped"
