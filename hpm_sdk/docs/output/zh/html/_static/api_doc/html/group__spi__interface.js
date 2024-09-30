var group__spi__interface =
[
    [ "spi_master_timing_config_t", "structspi__master__timing__config__t.html", [
      [ "clk_src_freq_in_hz", "structspi__master__timing__config__t.html#afa1613eb9c5cdef9fdb57eb337c83f8c", null ],
      [ "cs2sclk", "structspi__master__timing__config__t.html#af96ea528f3b57794c7e8432de7ef5c73", null ],
      [ "csht", "structspi__master__timing__config__t.html#ab0423d7034f7fa474079de79cdd0adec", null ],
      [ "sclk_freq_in_hz", "structspi__master__timing__config__t.html#a27234dc0ee0c0709adb8e03a256e75ba", null ]
    ] ],
    [ "spi_timing_config_t", "structspi__timing__config__t.html", [
      [ "master_config", "structspi__timing__config__t.html#a90ac9374c633e5f77596962520300859", null ]
    ] ],
    [ "spi_master_format_config_t", "structspi__master__format__config__t.html", [
      [ "addr_len_in_bytes", "structspi__master__format__config__t.html#a6e520a2ad02d36c9a533668c513ac05a", null ]
    ] ],
    [ "spi_common_format_config_t", "structspi__common__format__config__t.html", [
      [ "cpha", "structspi__common__format__config__t.html#a7c701dd9caff9d37a414909ef2f64371", null ],
      [ "cpol", "structspi__common__format__config__t.html#a4551ed3258f8e414898d0b1ec1874235", null ],
      [ "data_len_in_bits", "structspi__common__format__config__t.html#ae673051b9503727c7392cec1c437480c", null ],
      [ "data_merge", "structspi__common__format__config__t.html#ae9fb042cafeced22e81d78bd7c2bfebb", null ],
      [ "lsb", "structspi__common__format__config__t.html#a7fee1be394be1d9bea6aec710eb1c71f", null ],
      [ "mode", "structspi__common__format__config__t.html#a44e71a391681bdbb23de871329563220", null ],
      [ "mosi_bidir", "structspi__common__format__config__t.html#addace38f33b9d2d11b9de77e3bd11a7f", null ]
    ] ],
    [ "spi_format_config_t", "structspi__format__config__t.html", [
      [ "common_config", "structspi__format__config__t.html#aca68f5f5e29c87ed38b57f36b4ca77e3", null ],
      [ "master_config", "structspi__format__config__t.html#a848dc52df304d08430857d4939fcad80", null ]
    ] ],
    [ "spi_master_control_config_t", "structspi__master__control__config__t.html", [
      [ "addr_enable", "structspi__master__control__config__t.html#aa8641b8bfbac0c872484fa3829813b7b", null ],
      [ "addr_phase_fmt", "structspi__master__control__config__t.html#aa263aec2665ba9d6552e208d42799076", null ],
      [ "cmd_enable", "structspi__master__control__config__t.html#ae2ea18d885fd14920b6f3a81cd07887a", null ],
      [ "token_enable", "structspi__master__control__config__t.html#aa456a1182d9e6f932f976f8fdb0fb790", null ],
      [ "token_value", "structspi__master__control__config__t.html#a6d83382bee82065905fcd0c6c36bb206", null ]
    ] ],
    [ "spi_slave_control_config_t", "structspi__slave__control__config__t.html", [
      [ "slave_data_only", "structspi__slave__control__config__t.html#aac4b171e5eadbd515b19a90b5576d0c8", null ]
    ] ],
    [ "spi_common_control_config_t", "structspi__common__control__config__t.html", [
      [ "cs_index", "structspi__common__control__config__t.html#aaef58e57ce410d47830ff7d397adefcb", null ],
      [ "data_phase_fmt", "structspi__common__control__config__t.html#ade270abbbcfe0810b2a0edd85cdd4233", null ],
      [ "dummy_cnt", "structspi__common__control__config__t.html#a40f2304b0b01eee4236eb79150252eb8", null ],
      [ "rx_dma_enable", "structspi__common__control__config__t.html#ad39ae05df043d04e21bddb8af976bf4e", null ],
      [ "trans_mode", "structspi__common__control__config__t.html#adfca7e744e0d44634d9b38f7be284058", null ],
      [ "tx_dma_enable", "structspi__common__control__config__t.html#a956b1e54e7c59f53b56c69140f5d4571", null ]
    ] ],
    [ "spi_control_config_t", "structspi__control__config__t.html", [
      [ "common_config", "structspi__control__config__t.html#ad808dc64b56fca1e62005aaaf8618b70", null ],
      [ "master_config", "structspi__control__config__t.html#a96cd87a49bfc5810ea771c8fbb310cde", null ],
      [ "slave_config", "structspi__control__config__t.html#a74fadddc760f616fbfad225fbfc4dbc5", null ],
      [ "status_spi_master_busy", "group__spi__interface.html#gga07422cff4c3dd5075f91f87bd0e57ee7a2d497018c6ac935d124ce6c3a3eb4ec0", null ]
    ] ],
    [ "spi_addr_phase_format_t", "group__spi__interface.html#ga005ab1f2922a495cd72705c4f97806ef", [
      [ "spi_address_phase_format_single_io_mode", "group__spi__interface.html#gga005ab1f2922a495cd72705c4f97806efa190261bcad9b03c22a05c9d44ed4225b", null ],
      [ "spi_address_phase_format_dualquad_io_mode", "group__spi__interface.html#gga005ab1f2922a495cd72705c4f97806efaf81060a0bf7cf5a3800f0180b8d69ccb", null ]
    ] ],
    [ "spi_address_len_t", "group__spi__interface.html#ga2dfc87861824b591ae352a3c072c5b63", [
      [ "addrlen_8bit", "group__spi__interface.html#gga2dfc87861824b591ae352a3c072c5b63a437233c31d08f9439bedbcf88bc0a56c", null ],
      [ "addrlen_16bit", "group__spi__interface.html#gga2dfc87861824b591ae352a3c072c5b63a9b904ddbc71a5c73ac0a5d517a7607e3", null ],
      [ "addrlen_24bit", "group__spi__interface.html#gga2dfc87861824b591ae352a3c072c5b63a30989333162b71d95042e219a90c088c", null ],
      [ "addrlen_32bit", "group__spi__interface.html#gga2dfc87861824b591ae352a3c072c5b63ab0e9582af149b2ae9e2b48f9cfe40932", null ]
    ] ],
    [ "spi_cs2sclk_duration_t", "group__spi__interface.html#ga33e343fc2876a4886bcd808046ba8ebe", [
      [ "spi_cs2sclk_half_sclk_1", "group__spi__interface.html#gga33e343fc2876a4886bcd808046ba8ebeaf94ebaa71709afd9f6f4c3445227a729", null ],
      [ "spi_cs2sclk_half_sclk_2", "group__spi__interface.html#gga33e343fc2876a4886bcd808046ba8ebeac2b418b2429a6cc534e3ba11f2d0c36c", null ],
      [ "spi_cs2sclk_half_sclk_3", "group__spi__interface.html#gga33e343fc2876a4886bcd808046ba8ebea312a681b7bb0692606448ca9528ed793", null ],
      [ "spi_cs2sclk_half_sclk_4", "group__spi__interface.html#gga33e343fc2876a4886bcd808046ba8ebeaa1f01e9f9e4ee1f26da466705433c8a3", null ]
    ] ],
    [ "spi_cs_index_t", "group__spi__interface.html#ga51060f220285ddf82d48d15d3ec751bb", [
      [ "spi_cs_0", "group__spi__interface.html#gga51060f220285ddf82d48d15d3ec751bba04ddc15da2c1542ffd03dad5f0e4f376", null ],
      [ "spi_cs_1", "group__spi__interface.html#gga51060f220285ddf82d48d15d3ec751bbaed827d5345b80dc4d2e3096a54831ffd", null ],
      [ "spi_cs_2", "group__spi__interface.html#gga51060f220285ddf82d48d15d3ec751bbaa50fd87f07b77e031056562c486f0c13", null ],
      [ "spi_cs_3", "group__spi__interface.html#gga51060f220285ddf82d48d15d3ec751bbaabb5f8cce1299d172b265cdac1a831ee", null ]
    ] ],
    [ "spi_csht_duration_t", "group__spi__interface.html#ga410142b39b47da0d68fa76b42aa7e030", [
      [ "spi_csht_half_sclk_1", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030abd82a7856f4955ffa1cefbb2ff293fb3", null ],
      [ "spi_csht_half_sclk_2", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030a773dad60833d9f40f6769c51d7e73bea", null ],
      [ "spi_csht_half_sclk_3", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030a4cd196bb27440ad5ae065225a9da51f5", null ],
      [ "spi_csht_half_sclk_4", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030ae724ef94bfcb549f811fcf1b6ebdb844", null ],
      [ "spi_csht_half_sclk_5", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030adba4fdcf211cee3d9b7cd4d46b9b6d2e", null ],
      [ "spi_csht_half_sclk_6", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030ac143308845fb6a002ee6acd02045714c", null ],
      [ "spi_csht_half_sclk_7", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030a1979cd9f44e66499a4c3097bedfeab34", null ],
      [ "spi_csht_half_sclk_8", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030abab095143d449401f5d492a13e16fde7", null ],
      [ "spi_csht_half_sclk_9", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030a958920e56d23246f39cf0dcf99084148", null ],
      [ "spi_csht_half_sclk_10", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030aa0a04e8ff6835c991494327b2fe9d248", null ],
      [ "spi_csht_half_sclk_11", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030a81472251e57b6b3abf105989a14e3988", null ],
      [ "spi_csht_half_sclk_12", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030a20e9ad1c6d82de9ab4fec35958997b58", null ],
      [ "spi_csht_half_sclk_13", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030a4022b88297a903dcc85c6ad51f54555e", null ],
      [ "spi_csht_half_sclk_14", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030a74fdc26e3f64e8a6ea084de94b3435b1", null ],
      [ "spi_csht_half_sclk_15", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030aa918aacc182608444255e0da7eceec89", null ],
      [ "spi_csht_half_sclk_16", "group__spi__interface.html#gga410142b39b47da0d68fa76b42aa7e030a2ecf0f75bcca14605b7cfb7b265bfbee", null ]
    ] ],
    [ "spi_data_phase_format_t", "group__spi__interface.html#gafff636ea73cfd28e417690fcfcacc5f9", [
      [ "spi_single_io_mode", "group__spi__interface.html#ggafff636ea73cfd28e417690fcfcacc5f9afa1be05243c70c676721e8d938096115", null ],
      [ "spi_dual_io_mode", "group__spi__interface.html#ggafff636ea73cfd28e417690fcfcacc5f9af1e1ca2d0ebd45c2305977fe8d060938", null ],
      [ "spi_quad_io_mode", "group__spi__interface.html#ggafff636ea73cfd28e417690fcfcacc5f9a179a6b44f520254c8220f027c3035dcb", null ]
    ] ],
    [ "spi_directio_pin_t", "group__spi__interface.html#ga6deabf23d3377ce418a7993f368edfcf", [
      [ "hold_pin", "group__spi__interface.html#gga6deabf23d3377ce418a7993f368edfcfa6b49d8577c21651d3151a26c09893d79", null ],
      [ "wp_pin", "group__spi__interface.html#gga6deabf23d3377ce418a7993f368edfcfaea49b0f23d61f6464aa3563efc2b4974", null ],
      [ "miso_pin", "group__spi__interface.html#gga6deabf23d3377ce418a7993f368edfcfa7b665aeb7d309416d7131464b83749b6", null ],
      [ "mosi_pin", "group__spi__interface.html#gga6deabf23d3377ce418a7993f368edfcfa040ba68bb6c4bf0328e0dd63674b09c8", null ],
      [ "sclk_pin", "group__spi__interface.html#gga6deabf23d3377ce418a7993f368edfcfa370e29665ef702afa0a1da003190eb98", null ],
      [ "cs_pin", "group__spi__interface.html#gga6deabf23d3377ce418a7993f368edfcfa39fccb78c96524a19748b5f1fb87e331", null ]
    ] ],
    [ "spi_dma_enable_t", "group__spi__interface.html#ga2c8676764b385d09b4e9e2b4d353d8c1", [
      [ "spi_tx_dma_enable", "group__spi__interface.html#gga2c8676764b385d09b4e9e2b4d353d8c1a08d828f01f93e2552890d96467df5c91", null ],
      [ "spi_rx_dma_enable", "group__spi__interface.html#gga2c8676764b385d09b4e9e2b4d353d8c1adb471155f65aa3496c662d09c600297e", null ]
    ] ],
    [ "spi_dummy_count_t", "group__spi__interface.html#gac15a19c9674d3a82d5cd58bfbe9096ba", [
      [ "spi_dummy_count_1", "group__spi__interface.html#ggac15a19c9674d3a82d5cd58bfbe9096baa9a79496f619dc35cf573304b23daeb7c", null ],
      [ "spi_dummy_count_2", "group__spi__interface.html#ggac15a19c9674d3a82d5cd58bfbe9096baa76e0518b9444026b754f14565b008c30", null ],
      [ "spi_dummy_count_3", "group__spi__interface.html#ggac15a19c9674d3a82d5cd58bfbe9096baa1c49d9467b2c767d5020f07c157f0b05", null ],
      [ "spi_dummy_count_4", "group__spi__interface.html#ggac15a19c9674d3a82d5cd58bfbe9096baacf582dc4728f105408f70ff5ba747755", null ]
    ] ],
    [ "spi_interrupt_t", "group__spi__interface.html#ga8557f7a2d6b673c86868c02184980e12", [
      [ "spi_rx_fifo_overflow_int", "group__spi__interface.html#gga8557f7a2d6b673c86868c02184980e12a56948d2f74a9ea7f43b3e028f905d8f4", null ],
      [ "spi_tx_fifo_underflow_int", "group__spi__interface.html#gga8557f7a2d6b673c86868c02184980e12a358bee49efe4665b033c3e284e936437", null ],
      [ "spi_rx_fifo_threshold_int", "group__spi__interface.html#gga8557f7a2d6b673c86868c02184980e12a629039949e0fadcd4f87fc682cd99681", null ],
      [ "spi_tx_fifo_threshold_int", "group__spi__interface.html#gga8557f7a2d6b673c86868c02184980e12a096e74ab237d4f82d526bdb6530b09a2", null ],
      [ "spi_end_int", "group__spi__interface.html#gga8557f7a2d6b673c86868c02184980e12ac84380ad248d497ff43bbedb04c4c66d", null ],
      [ "spi_slave_cmd_int", "group__spi__interface.html#gga8557f7a2d6b673c86868c02184980e12a840fe3f2725b002cf0b2bfc117d13213", null ]
    ] ],
    [ "spi_mode_selection_t", "group__spi__interface.html#ga9ac2dd2dcd0b2c3b5fb1363eac489a3e", [
      [ "spi_master_mode", "group__spi__interface.html#gga9ac2dd2dcd0b2c3b5fb1363eac489a3eaa45f1c195fc0e4f77a6871bd3c72ad30", null ],
      [ "spi_slave_mode", "group__spi__interface.html#gga9ac2dd2dcd0b2c3b5fb1363eac489a3ea6d237dd86032fe3495c45320e9ba4afb", null ]
    ] ],
    [ "spi_sclk_idle_state_t", "group__spi__interface.html#gaa216e00c4ce27ab3897a36c72e617968", [
      [ "spi_sclk_low_idle", "group__spi__interface.html#ggaa216e00c4ce27ab3897a36c72e617968a6a05e63978b1c909f29fcd9e0afe2739", null ],
      [ "spi_sclk_high_idle", "group__spi__interface.html#ggaa216e00c4ce27ab3897a36c72e617968ab30339f1b568344b818345078b7a8d99", null ]
    ] ],
    [ "spi_sclk_sampling_clk_edges_t", "group__spi__interface.html#gab063d70616d6d55c73b01e9a1d2fb162", [
      [ "spi_sclk_sampling_odd_clk_edges", "group__spi__interface.html#ggab063d70616d6d55c73b01e9a1d2fb162adfa02e88e6f8e2e588681d72e7ec0740", null ],
      [ "spi_sclk_sampling_even_clk_edges", "group__spi__interface.html#ggab063d70616d6d55c73b01e9a1d2fb162aea2fabd92a138e8c88809d265a2d0408", null ]
    ] ],
    [ "spi_shift_direction_t", "group__spi__interface.html#gaa68518c16202382c2e1f1c7c66a9d53d", [
      [ "msb_first", "group__spi__interface.html#ggaa68518c16202382c2e1f1c7c66a9d53daf32736f3740a3bb0da46775f24314b51", null ],
      [ "lsb_first", "group__spi__interface.html#ggaa68518c16202382c2e1f1c7c66a9d53da58e7384444d0f08edde227a31593115e", null ]
    ] ],
    [ "spi_token_value_t", "group__spi__interface.html#gac0796b7f31e5676ab9e039b8dfa3b7f5", [
      [ "spi_token_value_0x00", "group__spi__interface.html#ggac0796b7f31e5676ab9e039b8dfa3b7f5a17a2324369c04c125198cf1e6bc32f18", null ],
      [ "spi_token_value_0x69", "group__spi__interface.html#ggac0796b7f31e5676ab9e039b8dfa3b7f5a3795ec4e8784940f64983927322a95b3", null ]
    ] ],
    [ "spi_trans_mode_t", "group__spi__interface.html#gae719b4eb51210f7a6878861fcb374d15", [
      [ "spi_trans_write_read_together", "group__spi__interface.html#ggae719b4eb51210f7a6878861fcb374d15ad2a478fbce4d16e6a53fda9d2a7d28a7", null ],
      [ "spi_trans_write_only", "group__spi__interface.html#ggae719b4eb51210f7a6878861fcb374d15a49d8050552ae2f123d9e5894d6d99c54", null ],
      [ "spi_trans_read_only", "group__spi__interface.html#ggae719b4eb51210f7a6878861fcb374d15a20a6bb5cff8d394455e770ab0f73c4b4", null ],
      [ "spi_trans_write_read", "group__spi__interface.html#ggae719b4eb51210f7a6878861fcb374d15a65f770f7ab912d205a692621390ff981", null ],
      [ "spi_trans_read_write", "group__spi__interface.html#ggae719b4eb51210f7a6878861fcb374d15a77520f7f2577b7e360fcae729d557ebb", null ],
      [ "spi_trans_write_dummy_read", "group__spi__interface.html#ggae719b4eb51210f7a6878861fcb374d15a427d193ff9c71ad266027b15c6ea8033", null ],
      [ "spi_trans_read_dummy_write", "group__spi__interface.html#ggae719b4eb51210f7a6878861fcb374d15a978ff206dd41af49c7e973a1277a6e61", null ],
      [ "spi_trans_no_data", "group__spi__interface.html#ggae719b4eb51210f7a6878861fcb374d15aacc4a2b50914746ead941136d219909d", null ],
      [ "spi_trans_dummy_write", "group__spi__interface.html#ggae719b4eb51210f7a6878861fcb374d15a19c72838dd5f1436b0d12764565d1f23", null ],
      [ "spi_trans_dummy_read", "group__spi__interface.html#ggae719b4eb51210f7a6878861fcb374d15a938f0767762b6a2f353bb987314826c5", null ]
    ] ],
    [ "spi_clear_interrupt_status", "group__spi__interface.html#ga9708ee3711c2126bf5abb15b304ecdff", null ],
    [ "spi_control_init", "group__spi__interface.html#gadfc7b3d8df21dcdb70b00ec76896512e", null ],
    [ "spi_directio_disable_output", "group__spi__interface.html#gaeb5f59746b951994a62af4833805f8f7", null ],
    [ "spi_directio_enable_output", "group__spi__interface.html#ga512b377ea6545958877dcd3f3b62722f", null ],
    [ "spi_directio_read", "group__spi__interface.html#ga494456b6c602ebb92342683413eb03c5", null ],
    [ "spi_directio_write", "group__spi__interface.html#ga64f70d73d56253d89d2229d30cffecd8", null ],
    [ "spi_disable_data_merge", "group__spi__interface.html#gad750cd2ccf1c1520693a7753dab10849", null ],
    [ "spi_disable_directio", "group__spi__interface.html#gac5b6dc4872ea3af07d46cd27c62ab559", null ],
    [ "spi_disable_dma", "group__spi__interface.html#ga46ec6520540c21decf07e5a82965a0c5", null ],
    [ "spi_disable_interrupt", "group__spi__interface.html#gaff0c4e65f11fd06a4aaf56bc49d4bf53", null ],
    [ "spi_disable_rx_dma", "group__spi__interface.html#gafc2c95d3d748afce3797778072931179", null ],
    [ "spi_disable_tx_dma", "group__spi__interface.html#ga4502ff3183ab82b24ab064452e948630", null ],
    [ "spi_enable_data_merge", "group__spi__interface.html#ga94f3f3128177a3b446f7c4ee7421a7e0", null ],
    [ "spi_enable_directio", "group__spi__interface.html#ga3c0c0d8dd106651b5df9f6b0e9bf8bec", null ],
    [ "spi_enable_dma", "group__spi__interface.html#ga68ac78d70cc136fe264d65f32d07b7f9", null ],
    [ "spi_enable_interrupt", "group__spi__interface.html#gaca5a18ff3cabe7bb292313b8ce20b154", null ],
    [ "spi_enable_rx_dma", "group__spi__interface.html#ga657e67d00646b00b6c973fa2ef547f97", null ],
    [ "spi_enable_tx_dma", "group__spi__interface.html#gac2db9a3228352512393aae049a3ea03c", null ],
    [ "spi_format_init", "group__spi__interface.html#ga6aa789fed3d323a5cf9d541649a909ec", null ],
    [ "spi_get_clock_phase", "group__spi__interface.html#ga7c7e5fea3347afff5c73b6a6626950e2", null ],
    [ "spi_get_clock_polarity", "group__spi__interface.html#ga2a16ce39c0a0adeae1186ab8716d3b38", null ],
    [ "spi_get_data_length_in_bits", "group__spi__interface.html#gaee5cb066ffeae9e6c6f3146ad9673679", null ],
    [ "spi_get_data_length_in_bytes", "group__spi__interface.html#gacdb3db6c42352184bacb17222cb7635f", null ],
    [ "spi_get_directio_enable_status", "group__spi__interface.html#ga1dc8eb6f679553b2f291fa75173f438d", null ],
    [ "spi_get_interrupt_status", "group__spi__interface.html#ga71c5807b3273462e5e32f6c379fe6250", null ],
    [ "spi_get_rx_fifo_size", "group__spi__interface.html#gaa2770ca9fa6405ec315339e62e70da33", null ],
    [ "spi_get_rx_fifo_valid_data_size", "group__spi__interface.html#ga84886a9846cb90b103a964b3e21f758b", null ],
    [ "spi_get_shift_direction", "group__spi__interface.html#gaaa5be5cb6d769696eb4dca6bba0f6161", null ],
    [ "spi_get_tx_fifo_size", "group__spi__interface.html#gac7530cb52d282a0f587dcaf0cc13aa78", null ],
    [ "spi_get_tx_fifo_valid_data_size", "group__spi__interface.html#ga018f780445a809c06c0079f56b4917c5", null ],
    [ "spi_is_active", "group__spi__interface.html#ga0043a6affc864f586ce9a91b3725ce66", null ],
    [ "spi_master_disable_address_phase", "group__spi__interface.html#ga84180238db73ab7d6341ce2bcc51c295", null ],
    [ "spi_master_disable_command_phase", "group__spi__interface.html#ga553a0ac19fd3138ddce04931e03307a6", null ],
    [ "spi_master_disable_token_transfer", "group__spi__interface.html#ga2fddd7749dca5624e87e063acc69e169", null ],
    [ "spi_master_enable_address_phase", "group__spi__interface.html#gaed110cd079923ebb28d014e64b23bf68", null ],
    [ "spi_master_enable_command_phase", "group__spi__interface.html#ga07fc6b8527da6e75e9f71d8308f6fa20", null ],
    [ "spi_master_enable_token_transfer", "group__spi__interface.html#ga1907108cb49846339378009cfbed6cfe", null ],
    [ "spi_master_get_cs2sclk_timing", "group__spi__interface.html#gafb3f576ac06f554109b2ff27edc3346c", null ],
    [ "spi_master_get_csht_timing", "group__spi__interface.html#gaeadbe0167ff59081d1e5451a8565ba6d", null ],
    [ "spi_master_get_data_phase_format", "group__spi__interface.html#gaadfbe7c0def75ad34d005bde61c92bdc", null ],
    [ "spi_master_get_default_control_config", "group__spi__interface.html#ga20fe4a9fd4254d69da5b3b5fa33f8f8c", null ],
    [ "spi_master_get_default_format_config", "group__spi__interface.html#ga31168318ca7a3f8145d6991412bffdb3", null ],
    [ "spi_master_get_default_timing_config", "group__spi__interface.html#ga3398ff3ef43abb865ba061fdac3922bd", null ],
    [ "spi_master_get_sclk_div", "group__spi__interface.html#gad37739361227074ad8669a6a3bf2035f", null ],
    [ "spi_master_set_address_phase_format", "group__spi__interface.html#ga91dfa8cf3ec60a584d8cfc556fd32a7c", null ],
    [ "spi_master_set_cs2sclk_timing", "group__spi__interface.html#gaeeca7594629b6890028b9c967415aa51", null ],
    [ "spi_master_set_csht_timing", "group__spi__interface.html#gaa5d631efc977c69f6979d91a6052fc53", null ],
    [ "spi_master_set_data_phase_format", "group__spi__interface.html#ga5b49daf30da4c1b259ad9b760055b7fb", null ],
    [ "spi_master_set_sclk_div", "group__spi__interface.html#gacfa3adaa305d91e7e24480e1a643bcaa", null ],
    [ "spi_master_set_token_value", "group__spi__interface.html#ga50cde01bb360e3609183229e451a920b", null ],
    [ "spi_master_timing_init", "group__spi__interface.html#ga5f947eba318d5cf434442208fa013890", null ],
    [ "spi_read_command", "group__spi__interface.html#ga8dc3d203a1773ffb50514cdb9bced308", null ],
    [ "spi_read_data", "group__spi__interface.html#ga8b614bbd1672d0e1abef6a3e95c1040f", null ],
    [ "spi_receive_fifo_reset", "group__spi__interface.html#ga9f13297d81585c938533cce5a246d163", null ],
    [ "spi_reset", "group__spi__interface.html#ga612e862742c37a8fb24d804f27d25c36", null ],
    [ "spi_set_address_len", "group__spi__interface.html#ga03f7b75ff650c1f629ddf57e5958d16c", null ],
    [ "spi_set_clock_phase", "group__spi__interface.html#ga661c40e2f8b145bfac40eaaf9b1f05eb", null ],
    [ "spi_set_clock_polarity", "group__spi__interface.html#ga0cc5dc04048e81f719b4b5f7cb31e063", null ],
    [ "spi_set_data_bits", "group__spi__interface.html#gaa4cff3b8b0cb8f5bf03c36e69d5ee5bb", null ],
    [ "spi_set_dummy_count", "group__spi__interface.html#ga495651ac82f1826dfb13dfe8e595bc8c", null ],
    [ "spi_set_read_data_count", "group__spi__interface.html#ga69f5bef4180ac170d76f93210b0a73a5", null ],
    [ "spi_set_rx_fifo_threshold", "group__spi__interface.html#gac397be35fa26126ce85d46ca94d13c03", null ],
    [ "spi_set_shift_direction", "group__spi__interface.html#ga9e420256bc43b0b31a9d196e8f3a8600", null ],
    [ "spi_set_transfer_mode", "group__spi__interface.html#gaeea2c67df32555cb1d06cd59a9cdce75", null ],
    [ "spi_set_tx_fifo_threshold", "group__spi__interface.html#gafc52355500b35061094306f08e1a13ce", null ],
    [ "spi_set_write_data_count", "group__spi__interface.html#ga64c2e39fd9475ae8c63c53b7b6525996", null ],
    [ "spi_setup_dma_transfer", "group__spi__interface.html#ga302f08c4fb52f1c0ac5049b2b91a8d87", null ],
    [ "spi_slave_disable_data_only", "group__spi__interface.html#ga684effa8061251b2444bab970ae0e147", null ],
    [ "spi_slave_enable_data_only", "group__spi__interface.html#ga4ef4c507dc9153fc8f3334a9c708881c", null ],
    [ "spi_slave_get_default_control_config", "group__spi__interface.html#ga011f364572dba586730f36c93f589557", null ],
    [ "spi_slave_get_default_format_config", "group__spi__interface.html#ga5a4c398026975ffff16080bdf1ba99f7", null ],
    [ "spi_slave_get_received_data_count", "group__spi__interface.html#ga4ed2c5dc7ca0a221cf687c2122a976e5", null ],
    [ "spi_slave_get_sent_data_count", "group__spi__interface.html#ga9a656cfa815f7005f5f73ca562f49da6", null ],
    [ "spi_slave_set_user_status", "group__spi__interface.html#ga5fb630925ae5271c3fcb67dd05e9ae94", null ],
    [ "spi_transfer", "group__spi__interface.html#ga6541675ce7395a67e896f900a6171133", null ],
    [ "spi_transmit_fifo_reset", "group__spi__interface.html#ga5c26a576ac4ad1c200f61bcdef602be7", null ],
    [ "spi_wait_for_busy_status", "group__spi__interface.html#ga3292349e298ddb9f64819946afcea7d2", null ],
    [ "spi_wait_for_idle_status", "group__spi__interface.html#ga0bd47db6a31f4592c25b0b0ce4d26635", null ],
    [ "spi_write_address", "group__spi__interface.html#gadf1e05aae5113bde63bc975a18a85f67", null ],
    [ "spi_write_command", "group__spi__interface.html#gad353177892d840687cd3ce3605bf0621", null ],
    [ "spi_write_data", "group__spi__interface.html#ga4f7dfe7ae3b9d7f280fc1aa47e228586", null ],
    [ "spi_write_read_data", "group__spi__interface.html#gabff410d7a08e77b7a8094df27d266605", null ]
];