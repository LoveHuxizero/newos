# bus manager makefile
MY_SRCDIR := $(GET_LOCAL_DIR)
MY_TARGETDIR := $(call TOBUILDDIR, $(MY_SRCDIR))
MY_TARGET :=  $(MY_TARGETDIR)/usb
ifeq ($(call FINDINLIST,$(MY_TARGET),$(ALL)),1)

MY_SRCS := \
	usb.c \
	usb_device.c \
	usb_enum.c \
	usb_hub.c \
	usb_pipe.c

MY_INCLUDES := $(STDINCLUDE)
MY_CFLAGS := $(KERNEL_CFLAGS)
MY_LIBS := $(LIBKERNEL)
MY_LIBPATHS :=
MY_DEPS :=
MY_LINKSCRIPT := $(KERNEL_ADDONS_DIR)/ldscripts/$(ARCH)/addon.ld

include templates/kernel_addons.mk

endif

