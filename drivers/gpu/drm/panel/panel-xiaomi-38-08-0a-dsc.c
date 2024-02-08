// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2024 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/module.h>
#include <linux/of.h>

#include <video/mipi_display.h>

#include <drm/display/drm_dsc.h>
#include <drm/display/drm_dsc_helper.h>
#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>

struct xiaomi_38_08_0a_dsc {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct drm_dsc_config dsc;
	struct gpio_desc *reset_gpio;
	bool prepared;
};

static inline
struct xiaomi_38_08_0a_dsc *to_xiaomi_38_08_0a_dsc(struct drm_panel *panel)
{
	return container_of(panel, struct xiaomi_38_08_0a_dsc, panel);
}

static void xiaomi_38_08_0a_dsc_reset(struct xiaomi_38_08_0a_dsc *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(10000, 11000);
}

static int xiaomi_38_08_0a_dsc_on(struct xiaomi_38_08_0a_dsc *ctx)
{
	struct mipi_dsi_device *dsi = ctx->dsi;
	struct device *dev = &dsi->dev;
	int ret;

	ret = mipi_dsi_dcs_exit_sleep_mode(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to exit sleep mode: %d\n", ret);
		return ret;
	}
	usleep_range(10000, 11000);

	ret = mipi_dsi_dcs_set_tear_on(dsi, MIPI_DSI_DCS_TEAR_MODE_VBLANK);
	if (ret < 0) {
		dev_err(dev, "Failed to set tear on: %d\n", ret);
		return ret;
	}

	mipi_dsi_dcs_write_seq(dsi, 0x9d, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x9e,
			       0x11, 0x00, 0x00, 0x89, 0x30, 0x80, 0x09, 0x60,
			       0x04, 0x38, 0x00, 0x08, 0x02, 0x1c, 0x02, 0x1c,
			       0x02, 0x00, 0x02, 0x0e, 0x00, 0x20, 0x00, 0xbb,
			       0x00, 0x07, 0x00, 0x0c, 0x0d, 0xb7, 0x0c, 0xb7,
			       0x18, 0x00, 0x10, 0xf0, 0x03, 0x0c, 0x20, 0x00,
			       0x06, 0x0b, 0x0b, 0x33, 0x0e, 0x1c, 0x2a, 0x38,
			       0x46, 0x54, 0x62, 0x69, 0x70, 0x77, 0x79, 0x7b,
			       0x7d, 0x7e, 0x01, 0x02, 0x01, 0x00, 0x09, 0x40,
			       0x09, 0xbe, 0x19, 0xfc, 0x19, 0xfa, 0x19, 0xf8,
			       0x1a, 0x38, 0x1a, 0x78, 0x1a, 0xb6, 0x2a, 0xf6,
			       0x2b, 0x34, 0x2b, 0x74, 0x3b, 0x74, 0x6b, 0xf4,
			       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);

	ret = mipi_dsi_dcs_set_column_address(dsi, 0x0000, 0x0437);
	if (ret < 0) {
		dev_err(dev, "Failed to set column address: %d\n", ret);
		return ret;
	}

	ret = mipi_dsi_dcs_set_page_address(dsi, 0x0000, 0x095f);
	if (ret < 0) {
		dev_err(dev, "Failed to set page address: %d\n", ret);
		return ret;
	}

	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq(dsi, 0xb0, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0xb7, 0x4f);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq(dsi, 0xb0, 0x02);
	mipi_dsi_dcs_write_seq(dsi, 0xec, 0x00, 0xc0, 0xc3, 0x43);
	mipi_dsi_dcs_write_seq(dsi, 0xb0, 0x0d);
	mipi_dsi_dcs_write_seq(dsi, 0xec, 0x19);
	mipi_dsi_dcs_write_seq(dsi, 0xb0, 0x06);
	mipi_dsi_dcs_write_seq(dsi, 0xe4, 0xd0);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq(dsi, 0xb0, 0x36);
	mipi_dsi_dcs_write_seq(dsi, 0xd3, 0x0f);
	mipi_dsi_dcs_write_seq(dsi, 0xf7, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq(dsi, 0xfc, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq(dsi, 0xb0, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0xe4, 0xa6, 0x75, 0xa3);
	mipi_dsi_dcs_write_seq(dsi, 0xe9,
			       0x11, 0x75, 0xa6, 0x75, 0xa3, 0x8d, 0x06, 0x20,
			       0x8c, 0xa2, 0x4e, 0x00, 0x32, 0x32);
	mipi_dsi_dcs_write_seq(dsi, 0xfc, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq(dsi, 0xdf, 0x83, 0x00, 0x10);
	mipi_dsi_dcs_write_seq(dsi, 0xb0, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0xe6, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq(dsi, 0xb0, 0x08);
	mipi_dsi_dcs_write_seq(dsi, 0xd4, 0x05);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq(dsi, 0xfc, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq(dsi, 0xb0, 0x16);
	mipi_dsi_dcs_write_seq(dsi, 0xd1, 0x2e);
	mipi_dsi_dcs_write_seq(dsi, 0xfc, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0xa5, 0xa5);
	msleep(90);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq(dsi, 0xb0, 0x06);
	mipi_dsi_dcs_write_seq(dsi, 0xb7, 0x20);
	mipi_dsi_dcs_write_seq(dsi, 0xb0, 0x05);
	mipi_dsi_dcs_write_seq(dsi, 0xb7, 0x93);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_WRITE_CONTROL_DISPLAY, 0x20);

	ret = mipi_dsi_dcs_set_display_brightness(dsi, 0x0000);
	if (ret < 0) {
		dev_err(dev, "Failed to set display brightness: %d\n", ret);
		return ret;
	}

	ret = mipi_dsi_dcs_set_display_on(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to set display on: %d\n", ret);
		return ret;
	}

	mipi_dsi_dcs_write_seq(dsi, 0x60, 0x00);

	return 0;
}

static int xiaomi_38_08_0a_dsc_off(struct xiaomi_38_08_0a_dsc *ctx)
{
	struct mipi_dsi_device *dsi = ctx->dsi;
	struct device *dev = &dsi->dev;
	int ret;

	ret = mipi_dsi_dcs_set_display_off(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to set display off: %d\n", ret);
		return ret;
	}
	msleep(20);

	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_WRITE_CONTROL_DISPLAY, 0x20);

	ret = mipi_dsi_dcs_enter_sleep_mode(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to enter sleep mode: %d\n", ret);
		return ret;
	}
	msleep(120);

	return 0;
}

static int xiaomi_38_08_0a_dsc_prepare(struct drm_panel *panel)
{
	struct xiaomi_38_08_0a_dsc *ctx = to_xiaomi_38_08_0a_dsc(panel);
	struct device *dev = &ctx->dsi->dev;

	struct drm_dsc_picture_parameter_set pps;

	int ret;

	if (ctx->prepared)
		return 0;

	xiaomi_38_08_0a_dsc_reset(ctx);

	ret = xiaomi_38_08_0a_dsc_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		return ret;
	}

	drm_dsc_pps_payload_pack(&pps, &ctx->dsc);

	ret = mipi_dsi_picture_parameter_set(ctx->dsi, &pps);
	if (ret < 0) {
		dev_err(panel->dev, "failed to transmit PPS: %d\n", ret);
		return ret;
	}

	ret = mipi_dsi_compression_mode(ctx->dsi, true);
	if (ret < 0) {
		dev_err(dev, "failed to enable compression mode: %d\n", ret);
		return ret;
	}

	msleep(28); /* TODO: Is this panel-dependent? */

	ctx->prepared = true;

	return 0;
}

static int xiaomi_38_08_0a_dsc_unprepare(struct drm_panel *panel)
{
	struct xiaomi_38_08_0a_dsc *ctx = to_xiaomi_38_08_0a_dsc(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	if (!ctx->prepared)
		return 0;

	ret = xiaomi_38_08_0a_dsc_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);

	ctx->prepared = false;
	return 0;
}

static const struct drm_display_mode xiaomi_38_08_0a_dsc_mode = {
	.clock = (1080 + 16 + 8 + 8) * (2400 + 600 + 32 + 560) * 60 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 16,
	.hsync_end = 1080 + 16 + 8,
	.htotal = 1080 + 16 + 8 + 8,
	.vdisplay = 2400,
	.vsync_start = 2400 + 600,
	.vsync_end = 2400 + 600 + 32,
	.vtotal = 2400 + 600 + 32 + 560,
	.width_mm = 70,
	.height_mm = 155,
};

static int xiaomi_38_08_0a_dsc_get_modes(struct drm_panel *panel,
				       struct drm_connector *connector)
{
	struct drm_display_mode *mode;

	mode = drm_mode_duplicate(connector->dev, &xiaomi_38_08_0a_dsc_mode);
	if (!mode)
		return -ENOMEM;

	drm_mode_set_name(mode);

	mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
	connector->display_info.width_mm = mode->width_mm;
	connector->display_info.height_mm = mode->height_mm;
	drm_mode_probed_add(connector, mode);

	return 1;
}

static const struct drm_panel_funcs xiaomi_38_08_0a_dsc_panel_funcs = {
	.prepare = xiaomi_38_08_0a_dsc_prepare,
	.unprepare = xiaomi_38_08_0a_dsc_unprepare,
	.get_modes = xiaomi_38_08_0a_dsc_get_modes,
};

static int xiaomi_38_08_0a_dsc_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct xiaomi_38_08_0a_dsc *ctx;
	int ret;

	ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO_BURST |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS | MIPI_DSI_MODE_LPM;

	drm_panel_init(&ctx->panel, dev, &xiaomi_38_08_0a_dsc_panel_funcs,
		       DRM_MODE_CONNECTOR_DSI);
	ctx->panel.prepare_prev_first = true;

	drm_panel_add(&ctx->panel);

	/* This panel only supports DSC; unconditionally enable it */
	dsi->dsc = &ctx->dsc;

	ctx->dsc.dsc_version_major = 1;
	ctx->dsc.dsc_version_minor = 1;

	// TODO: Pass slice_per_pkt = 2
	ctx->dsc.slice_height = 8;
	ctx->dsc.slice_width = 540;
	/*
	 * hdisplay should be read from the selected mode once
	 * it is passed back to drm_panel (in prepare?)
	 */
	WARN_ON(1080 % ctx->dsc.slice_width);
	ctx->dsc.slice_count = 1080 / ctx->dsc.slice_width;
	ctx->dsc.bits_per_component = 8;
	ctx->dsc.bits_per_pixel = 8 << 4; /* 4 fractional bits */
	ctx->dsc.block_pred_enable = true;

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to attach to DSI host: %d\n", ret);
		drm_panel_remove(&ctx->panel);
		return ret;
	}

	return 0;
}

static void xiaomi_38_08_0a_dsc_remove(struct mipi_dsi_device *dsi)
{
	struct xiaomi_38_08_0a_dsc *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id xiaomi_38_08_0a_dsc_of_match[] = {
	{ .compatible = "mdss,xiaomi-38-08-0a-dsc" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, xiaomi_38_08_0a_dsc_of_match);

static struct mipi_dsi_driver xiaomi_38_08_0a_dsc_driver = {
	.probe = xiaomi_38_08_0a_dsc_probe,
	.remove = xiaomi_38_08_0a_dsc_remove,
	.driver = {
		.name = "panel-xiaomi-38-08-0a-dsc",
		.of_match_table = xiaomi_38_08_0a_dsc_of_match,
	},
};
module_mipi_dsi_driver(xiaomi_38_08_0a_dsc_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for xiaomi 38 08 0a cmd mode dsc dsi panel");
MODULE_LICENSE("GPL");
