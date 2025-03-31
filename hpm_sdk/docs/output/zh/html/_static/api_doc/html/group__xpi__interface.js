var group__xpi__interface =
[
    [ "xpi_xfer_ctx_t", "structxpi__xfer__ctx__t.html", [
      [ "addr", "structxpi__xfer__ctx__t.html#a200f2b24abe4af518759c1d5c09991fa", null ],
      [ "buf", "structxpi__xfer__ctx__t.html#a12e4716f7dac23cca70d83be545cbba8", null ],
      [ "channel", "structxpi__xfer__ctx__t.html#a3d9fcbd593d58a9d221276029e58892f", null ],
      [ "cmd_type", "structxpi__xfer__ctx__t.html#ae8c128ca360931e0a0a03ba01fb31deb", null ],
      [ "seq_idx", "structxpi__xfer__ctx__t.html#a3d8dfc9be3829aed6403d5077d172481", null ],
      [ "seq_num", "structxpi__xfer__ctx__t.html#a94e26ba8014e815e40c3fb79b23de200", null ],
      [ "xfer_size", "structxpi__xfer__ctx__t.html#a7cf9e14324e1792f67631255e9059672", null ]
    ] ],
    [ "xpi_instr_seq_t", "structxpi__instr__seq__t.html", [
      [ "entry", "structxpi__instr__seq__t.html#a7c151a3161a8160c6fb0d8ec678e3835", null ]
    ] ],
    [ "xpi_config_t", "structxpi__config__t.html", [
      [ "access_flags", "structxpi__config__t.html#a894630abdca081526ea807123916ab89", null ],
      [ "enable_differential_clk", "structxpi__config__t.html#a7756d4e71b6569ec07fbf03e18f7aece", null ],
      [ "reserved0", "structxpi__config__t.html#ae6038bdadc1b75237886517e85d48fdd", null ],
      [ "reserved1", "structxpi__config__t.html#a14dde57eedcb7356cd925f9cc5325176", null ],
      [ "rx_watermark_in_dwords", "structxpi__config__t.html#a4cd4a8b16cea637f059b1f3184f6a2ed", null ],
      [ "rxclk_src", "structxpi__config__t.html#aa9d79f22388e192bb66c59d4dc26495c", null ],
      [ "tx_watermark_in_dwords", "structxpi__config__t.html#a572b67e82d4ea81d3a0a752047223469", null ]
    ] ],
    [ "xpi_device_config_t", "structxpi__device__config__t.html", [
      [ "ahb_read_seq_idx", "structxpi__device__config__t.html#a2bda01908c18ecf4aa6a954a4996c17f", null ],
      [ "ahb_read_seq_num", "structxpi__device__config__t.html#a611dde22f988a70479cfe65d454d73d8", null ],
      [ "ahb_write_seq_idx", "structxpi__device__config__t.html#ad6db645cf9d3d962632513bacd3447ed", null ],
      [ "ahb_write_seq_num", "structxpi__device__config__t.html#aada355234a43cc78434fe80de51e3e83", null ],
      [ "ahb_write_wait_interval", "structxpi__device__config__t.html#a9e41b2e7914b6fbedeba7af07748db22", null ],
      [ "column_addr_size", "structxpi__device__config__t.html#aba924e957b473158be624c4e87ed51ce", null ],
      [ "cs_hold_time", "structxpi__device__config__t.html#a0af64ddf05b9eadb6d5ede5fd1455719", null ],
      [ "cs_interval", "structxpi__device__config__t.html#a8266c0d8b3e63ecf687d0a05135f430b", null ],
      [ "cs_setup_time", "structxpi__device__config__t.html#a0ad3d621cae662482abed21983367441", null ],
      [ "data_valid_time", "structxpi__device__config__t.html#a8b86866e42c8d57771fe6834d80cd35e", null ],
      [ "dly_target", "structxpi__device__config__t.html#a5562dda209b9024da117c0ba86febe89", null ],
      [ "enable_word_address", "structxpi__device__config__t.html#aecc96d8764a9cfd3e33b5172f152a531", null ],
      [ "enable_write_mask", "structxpi__device__config__t.html#a9a8f84bef16885df1f9631ffd907d058", null ],
      [ "reserved0", "structxpi__device__config__t.html#aa26dc87d434236edb6f630ce19e0396b", null ],
      [ "reserved1", "structxpi__device__config__t.html#aa81b1ce0a1fea8f50636602c04de4b24", null ],
      [ "reserved2", "structxpi__device__config__t.html#af443cf77f92cf1ca888d7c28c03bf7b0", null ],
      [ "serial_root_clk_freq", "structxpi__device__config__t.html#a1299e635b91de8810132a5168254f6cc", null ],
      [ "size_in_kbytes", "structxpi__device__config__t.html#aac0e640e5578d411924a211fb7922e37", null ]
    ] ],
    [ "xpi_ahb_buffer_cfg_t", "structxpi__ahb__buffer__cfg__t.html", [
      [ "buf_size_in_dword", "structxpi__ahb__buffer__cfg__t.html#a0e8781b79396614a859480888b945d1e", null ],
      [ "enable_prefetch", "structxpi__ahb__buffer__cfg__t.html#a8d95ad3b59d7b47fed9d193876767931", null ],
      [ "entry", "structxpi__ahb__buffer__cfg__t.html#af063d7548348482403cd403ad8ef5dd4", null ],
      [ "master_idx", "structxpi__ahb__buffer__cfg__t.html#a8560a3e3503c660a8088da3471084458", null ],
      [ "priority", "structxpi__ahb__buffer__cfg__t.html#af88dcb83d964dfa831a35c585c8901a3", null ]
    ] ],
    [ "xpi_driver_interface_t", "structxpi__driver__interface__t.html", [
      [ "config_ahb_buffer", "structxpi__driver__interface__t.html#a9c4713d5736fd1c00f7367304f90605c", null ],
      [ "config_device", "structxpi__driver__interface__t.html#acd3f56a3e5351dd0f9b996560bb8af24", null ],
      [ "get_abs_apb_xfer_addr", "structxpi__driver__interface__t.html#ab4bd4e99de5364a1c028cbfacc1c35c0", null ],
      [ "get_default_config", "structxpi__driver__interface__t.html#a367208804f7d3a54ee31d6119939790f", null ],
      [ "get_default_device_config", "structxpi__driver__interface__t.html#ab2e70678d09704b0d80a9d61df865dba", null ],
      [ "init", "structxpi__driver__interface__t.html#a4c7e410062f2aeb735acfb8b487188a9", null ],
      [ "is_idle", "structxpi__driver__interface__t.html#a87dd5588cb0d12ab4864d0b2351363a9", null ],
      [ "software_reset", "structxpi__driver__interface__t.html#a74c62da8706989c08b63dfe842d183b7", null ],
      [ "transfer_blocking", "structxpi__driver__interface__t.html#aa71f539255fa755246591818d9518bb3", null ],
      [ "update_dllcr", "structxpi__driver__interface__t.html#ae8efbc83ac984770681617877e4f0c12", null ],
      [ "update_instr_table", "structxpi__driver__interface__t.html#a882c69bcbc429527b26ba8812dd97bd9", null ],
      [ "version", "structxpi__driver__interface__t.html#af2e2d152e59ab867e4d7033319f61cf9", null ]
    ] ],
    [ "SUB_INSTR", "group__xpi__interface.html#ga22ab53c0fd42209793826eb9ad9f495c", null ],
    [ "XPI_1PAD", "group__xpi__interface.html#gae70bcef08c9c1368b392cc399bb67fba", null ],
    [ "XPI_2PADS", "group__xpi__interface.html#ga2e890b80c9019226a9ef589aafd51653", null ],
    [ "XPI_4PADS", "group__xpi__interface.html#gadb9704bc4d8ed9e74fbd06982d95103d", null ],
    [ "XPI_8PADS", "group__xpi__interface.html#gaab900b90c87c36a05db8731a85a7b452", null ],
    [ "XPI_INSTR_SEQ", "group__xpi__interface.html#gafd78a0f01eef333936a21a00ff978395", null ],
    [ "XPI_PHASE_CADDR_DDR", "group__xpi__interface.html#gacb02b4b5c6450ef0c53f7ab02351de07", null ],
    [ "XPI_PHASE_CADDR_SDR", "group__xpi__interface.html#gaf1a3a010126a8968dc894e5db06df941", null ],
    [ "XPI_PHASE_CMD_DDR", "group__xpi__interface.html#ga477baae32a3f5d1ec4a2a7376fde1540", null ],
    [ "XPI_PHASE_CMD_SDR", "group__xpi__interface.html#ga8efb6025a0154f17aca1df838192a816", null ],
    [ "XPI_PHASE_DUMMY_DDR", "group__xpi__interface.html#gaba7fbb64bec24e87de9a3586f3a20c70", null ],
    [ "XPI_PHASE_DUMMY_RWDS_DDR", "group__xpi__interface.html#ga4045ef311ca41a96e99642e5efbd2c02", null ],
    [ "XPI_PHASE_DUMMY_RWDS_SDR", "group__xpi__interface.html#ga268c31c9fa11de29cc554972a79e184a", null ],
    [ "XPI_PHASE_DUMMY_SDR", "group__xpi__interface.html#ga598500c79c0c98016c61e8a4deaea8c9", null ],
    [ "XPI_PHASE_MODE4_DDR", "group__xpi__interface.html#ga556664184f9adf744ea53aa346591493", null ],
    [ "XPI_PHASE_MODE4_SDR", "group__xpi__interface.html#ga34ff4e62e0ba90a4ec57fd547be267fa", null ],
    [ "XPI_PHASE_MODE8_DDR", "group__xpi__interface.html#gab8da0ca4327874d6b342515267083bf2", null ],
    [ "XPI_PHASE_MODE8_SDR", "group__xpi__interface.html#gad63ee604b3311e60409f71deb52870e4", null ],
    [ "XPI_PHASE_RADDR_DDR", "group__xpi__interface.html#gaea167c8439f6cc38f6013f9d23992fba", null ],
    [ "XPI_PHASE_RADDR_SDR", "group__xpi__interface.html#ga11dc53eccf7a88c727f6dfbf34eb820b", null ],
    [ "XPI_PHASE_READ_DDR", "group__xpi__interface.html#gacacfd5649959ba5095e6394c1d87412f", null ],
    [ "XPI_PHASE_READ_SDR", "group__xpi__interface.html#gab7681cdb6df79ac3725b0d215dd78959", null ],
    [ "XPI_PHASE_STOP", "group__xpi__interface.html#ga807627d5215e8a9a715c286d57c2d719", null ],
    [ "XPI_PHASE_WRITE_DDR", "group__xpi__interface.html#ga254f9f8c9d97bf25af258227ffa2dc02", null ],
    [ "XPI_PHASE_WRITE_SDR", "group__xpi__interface.html#ga075ab8935c4653e55d9a7fff985690d1", null ],
    [ "XPI_Type", "group__xpi__interface.html#ga87560204ea6254a4c1b7dbbbae1bf60b", [
      [ "xpi_dll_half_cycle", "group__xpi__interface.html#gga18813f5f63803020b8e95e5d83c0417aad4a84cc114dce34010ddffc171232796", null ],
      [ "xpi_dll_quarter_cycle", "group__xpi__interface.html#gga18813f5f63803020b8e95e5d83c0417aabdee6c2c09dd2c5b5c6be6f9966b1119", null ],
      [ "xpi_dll_sdr_default_cycle", "group__xpi__interface.html#gga18813f5f63803020b8e95e5d83c0417aa145f4f5da56c0a272c3cda070c9e5607", null ],
      [ "xpi_dll_ddr_default_cycle", "group__xpi__interface.html#gga18813f5f63803020b8e95e5d83c0417aacb6636aa8f605d13e8d0458fd41afe31", null ],
      [ "status_xpi_apb_jump_on_cs", "group__xpi__interface.html#gga3625aae0fb91cd50e743ac53bb2e9bb3a1383558c122092c54b8314d1b02817f0", null ],
      [ "status_xpi_apb_unknown_inst", "group__xpi__interface.html#gga3625aae0fb91cd50e743ac53bb2e9bb3a71d3523b453b9fd03d19aeadb95f5922", null ],
      [ "status_xpi_apb_dummy_sdr_in_ddr_seq", "group__xpi__interface.html#gga3625aae0fb91cd50e743ac53bb2e9bb3adf54c0e4d302a631603925f633dd0e9f", null ],
      [ "status_xpi_apb_dummy_ddr_in_sdr_seq", "group__xpi__interface.html#gga3625aae0fb91cd50e743ac53bb2e9bb3a3cee604b4b549d4accb75efcde42a831", null ],
      [ "status_xpi_apb_exceed_addr_range", "group__xpi__interface.html#gga3625aae0fb91cd50e743ac53bb2e9bb3afd5ae700f74e3c206bc0d7baedf3edfa", null ],
      [ "status_xpi_apb_seq_timeout", "group__xpi__interface.html#gga3625aae0fb91cd50e743ac53bb2e9bb3a9874b2d975b8e01270a5b8649c005a09", null ],
      [ "status_xpi_apb_cross_boundary", "group__xpi__interface.html#gga3625aae0fb91cd50e743ac53bb2e9bb3a155d12963d729dd044142577462329d5", null ]
    ] ],
    [ "xpi_apb_xfer_type_t", "group__xpi__interface.html#ga23bcf72f7d797a4992af3ccb0f560479", [
      [ "xpi_apb_xfer_type_cmd", "group__xpi__interface.html#gga23bcf72f7d797a4992af3ccb0f560479a77e6b01adbe8fe706b352d0602a080e4", null ],
      [ "xpi_apb_xfer_type_config", "group__xpi__interface.html#gga23bcf72f7d797a4992af3ccb0f560479a253dbe5287a11a3641598984dfc78850", null ],
      [ "xpi_apb_xfer_type_read", "group__xpi__interface.html#gga23bcf72f7d797a4992af3ccb0f560479aa5b71afdb7e287f96d0c813371903c69", null ],
      [ "xpi_apb_xfer_type_write", "group__xpi__interface.html#gga23bcf72f7d797a4992af3ccb0f560479ad7b591173364117baa19b829b0e13c04", null ]
    ] ],
    [ "xpi_channel_t", "group__xpi__interface.html#gac593d19770e78e26f3e26e197486900b", [
      [ "xpi_channel_a1", "group__xpi__interface.html#ggac593d19770e78e26f3e26e197486900babba9b9fa4a60013dcc9bbd63dd781426", null ],
      [ "xpi_channel_a2", "group__xpi__interface.html#ggac593d19770e78e26f3e26e197486900ba08d8dc32ea45502f71b23e05e8c3953f", null ],
      [ "xpi_channel_b1", "group__xpi__interface.html#ggac593d19770e78e26f3e26e197486900bab8963315a314c312a867dcf8382a3b07", null ],
      [ "xpi_channel_b2", "group__xpi__interface.html#ggac593d19770e78e26f3e26e197486900baea6f1e6103922694c6dbf4e84af409b9", null ]
    ] ],
    [ "xpi_io_group_t", "group__xpi__interface.html#ga9051025d6b0fd0195c3224025c9ebcd0", [
      [ "xpi_io_1st_group", "group__xpi__interface.html#gga9051025d6b0fd0195c3224025c9ebcd0af2aed325a140ef43792cfb441164cf8c", null ],
      [ "xpi_io_2nd_group", "group__xpi__interface.html#gga9051025d6b0fd0195c3224025c9ebcd0ab25622dec2723f22aa25822a4865f7c5", null ]
    ] ],
    [ "xpi_rxclksrc_type_t", "group__xpi__interface.html#ga2a84113527f0b7d617a6b219974b3a8a", [
      [ "xpi_rxclksrc_internal_loopback", "group__xpi__interface.html#gga2a84113527f0b7d617a6b219974b3a8aa4ca7c4ec4e22cd44ee28241be0820c86", null ],
      [ "xpi_rxclksrc_dqs_loopback", "group__xpi__interface.html#gga2a84113527f0b7d617a6b219974b3a8aa2364cb8ae29311f51ae28e5122812fa6", null ],
      [ "xpi_rxclksrc_external_dqs", "group__xpi__interface.html#gga2a84113527f0b7d617a6b219974b3a8aa55ee80f40a5e62b6ef2220eac9a70a4a", null ]
    ] ],
    [ "xpi_xfer_channel_t", "group__xpi__interface.html#ga1b1f60773ddc963ed77118b58caa8c6b", [
      [ "xpi_xfer_channel_a1", "group__xpi__interface.html#gga1b1f60773ddc963ed77118b58caa8c6bae1c97526cf797ebfc6ffd2d464dc1933", null ],
      [ "xpi_xfer_channel_a2", "group__xpi__interface.html#gga1b1f60773ddc963ed77118b58caa8c6bab7710d7d716ea74a0c92564da91bb67f", null ],
      [ "xpi_xfer_channel_b1", "group__xpi__interface.html#gga1b1f60773ddc963ed77118b58caa8c6bab43fe0f727712e8d21102651ee349ee2", null ],
      [ "xpi_xfer_channel_b2", "group__xpi__interface.html#gga1b1f60773ddc963ed77118b58caa8c6ba9bd5a04b4393f75dd670abc069f0bbd9", null ],
      [ "xpi_xfer_channel_auto", "group__xpi__interface.html#gga1b1f60773ddc963ed77118b58caa8c6baf48d92571e43ca16b47afc9813becc32", null ]
    ] ],
    [ "xpi_xfer_mode_t", "group__xpi__interface.html#ga6a5e0dc57bf7c78e40e8ec9229db094f", [
      [ "xpi_xfer_mode_polling", "group__xpi__interface.html#gga6a5e0dc57bf7c78e40e8ec9229db094fa9e9217e4b2a3d69cb6041149dca4cf9d", null ],
      [ "xpi_xfer_mode_dma", "group__xpi__interface.html#gga6a5e0dc57bf7c78e40e8ec9229db094fab329940d2f0d825b20e444ac78481284", null ],
      [ "xpi_xfer_mode_interrupt", "group__xpi__interface.html#gga6a5e0dc57bf7c78e40e8ec9229db094fa23470ffb2aec2f56baf8a5a0f8a833ef", null ]
    ] ]
];