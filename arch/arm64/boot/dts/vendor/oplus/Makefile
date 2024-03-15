
# add-overlay defines the target with following naming convention:
# <base>-<board>-dtbs = base.dtb board.dtbo
#
# Combined dtb target is also generated using the fdt_overlay tool.
# dtb-y += <base>-<board>.dtb

add-overlays = $(foreach o,$1,$(foreach b,$2,$(eval $(basename $b)-$(basename $o)-dtbs = $b $o) $(basename $b)-$(basename $o).dtb))

# kalama-dtb-y is list of DTBs to install when doing non-overlay build
# kalama-overlays-dtb-y is list of DTBs and DTBOs to install when doing overlay-supported build
# see DTB_TYPES from scripts/Makefile.dtbinst and install_dtbs from build.config.msm.common


KHAJE_BASE_DTB += khaje.dtb

KHAJE_BOARDS += \
                 messi_2172f_overlay.dtbo \
                 zoe_23697_overlay.dtbo \
                 zoe_23698_overlay.dtbo \
		 zoe_23699_overlay.dtbo

#bengal-dtb-$(CONFIG_ARCH_KHAJE) += \
        $(call add-overlays, $(KHAJE_BOARDS) ,$(KHAJE_BASE_DTB))
#bengal-overlays-dtb-$(CONFIG_ARCH_KHAJE) += $(KHAJE_BOARDS) $(KHAJE_BASE_DTB)
#dtb-y += $(bengal-dtb-y)

bengal-overlays-dtb-y += $(KHAJE_BOARDS) $(KHAJE_BASE_DTB)
dtb-y += $(KHAJE_BOARDS) $(KHAJE_BASE_DTB)

always-y	:= $(dtb-y)
subdir-y	:= $(dts-dirs)
clean-files	:= *.dtb *.dtbo
