var group__sdp__interface =
[
    [ "sdp_crypto_ctx_t", "structsdp__crypto__ctx__t.html", [
      [ "buf0", "structsdp__crypto__ctx__t.html#af4f0e2e8b5ce344be70814b9e2749f73", null ],
      [ "buf1", "structsdp__crypto__ctx__t.html#a66f48d17afdf104405886d1408617c50", null ],
      [ "buf2", "structsdp__crypto__ctx__t.html#a9194d10c6b1b5354695b20dfa028bf1c", null ],
      [ "buf3", "structsdp__crypto__ctx__t.html#ad95ac82c35baad6b729995d3feb9d74f", null ],
      [ "crypto_algo", "structsdp__crypto__ctx__t.html#a38ba17f554aaf4b7ac8f43c0d685439e", null ],
      [ "key_bits", "structsdp__crypto__ctx__t.html#a31930045628a0c045de0e2985803d766", null ],
      [ "key_idx", "structsdp__crypto__ctx__t.html#a3f7250e0fcae07a8a92e42abaa9d86b3", null ],
      [ "sdp_pkt", "structsdp__crypto__ctx__t.html#ae5d12bebbfd2c5644697f58e8d107fbb", null ]
    ] ],
    [ "sdp_dma_ctx_t", "structsdp__dma__ctx__t.html", [
      [ "sdp_pkt", "structsdp__dma__ctx__t.html#ab47ab8c708542b3331e180ea5ee4424c", null ]
    ] ],
    [ "sdp_hash_ctx_t", "structsdp__hash__ctx__t.html", [
      [ "internal", "structsdp__hash__ctx__t.html#aedfe17c78ecf8f15ea8d86e74af52665", null ],
      [ "sdp_pkt", "structsdp__hash__ctx__t.html#a2880a289fccbf81b99db891a3515a6a0", null ]
    ] ],
    [ "sdp_action_t", "structsdp__action__t.html", [
      [ "crypto_alg", "structsdp__action__t.html#a53f2f6a4982647293c3bec1209376cdf", null ],
      [ "crypto_mode", "structsdp__action__t.html#acf96fcfcff29393e207c95c89116a1d9", null ],
      [ "crypto_op", "structsdp__action__t.html#a901a0772815143509f8779d5aa19e8e5", null ],
      [ "hash_alg", "structsdp__action__t.html#a40d6e7901eca7d060c91a808ccaf153e", null ],
      [ "hash_check", "structsdp__action__t.html#ac762642a85859981f1e929d755459bef", null ],
      [ "hash_mode", "structsdp__action__t.html#af8cfee1f6f061efc411b6869e3f295b9", null ],
      [ "input_swap_mode", "structsdp__action__t.html#a274a0e755f388157d47c8cc6f3baecfb", null ],
      [ "key_bits", "structsdp__action__t.html#a83e8bc5ac01e27f486c1e46240cb05f1", null ],
      [ "key_index", "structsdp__action__t.html#aa4339ed8b76db444cbbccb6cf33b41f2", null ],
      [ "key_swap_mode", "structsdp__action__t.html#afa9f575eff5f8b302a219e55ef9731b8", null ],
      [ "op", "structsdp__action__t.html#abe6b4d527c2fc3c8a284a9683ee78461", null ],
      [ "output_swap_mode", "structsdp__action__t.html#a7750d7e62b61fbb10908554a7aa7e085", null ]
    ] ],
    [ "AES_128_KEY_SIZE", "group__sdp__interface.html#gaf0c555c508d898596911c3b7ec01fe74", null ],
    [ "AES_256_KEY_SIZE", "group__sdp__interface.html#gaf503c3f340dbc2edc8134997943456d0", null ],
    [ "AES_BLOCK_SIZE", "group__sdp__interface.html#gaf19ab913a847ad1e91c5291215116de1", null ],
    [ "HASH_BLOCK_SIZE", "group__sdp__interface.html#ga7b65d39b4e3e3b991ad75149530595a9", null ],
    [ "SDP_PKT_CTRL_CHAIN_MASK", "group__sdp__interface.html#ga71a87425d71b51399de6995e9ba4872d", null ],
    [ "SDP_PKT_CTRL_CIPHIV_MASK", "group__sdp__interface.html#ga5606cd14ab32a74f06fe204b3dba5094", null ],
    [ "SDP_PKT_CTRL_DERSEMA_MASK", "group__sdp__interface.html#gac27e0b37d01ea11ec337a0ae6e0e63ef", null ],
    [ "SDP_PKT_CTRL_HASHFINISH_MASK", "group__sdp__interface.html#ga484e51b4454437c30a7cd5f7b1814479", null ],
    [ "SDP_PKT_CTRL_HASHINIT_MASK", "group__sdp__interface.html#gad6ef9125058efa497a90f0528dff9c0b", null ],
    [ "SM4_BLOCK_SIZE", "group__sdp__interface.html#gae6af6c781da311d81ddbd242f068c697", null ],
    [ "SM4_KEY_SIZE", "group__sdp__interface.html#gab2c7defe2c4ca8e3991bb7e2efaf31f9", null ],
    [ "sdp_aes_ctx_t", "group__sdp__interface.html#ga848c82867ca6e64f519699b37713b15a", null ],
    [ "sdp_aes_key_bits_t", "group__sdp__interface.html#gab26373f1b0a85e72718dc600370dc5d3", null ],
    [ "sdp_aes_op_t", "group__sdp__interface.html#ga8fa52f2ebc84e79a5f1e43c1d89ccdab", null ],
    [ "sdp_pkt_struct_t", "group__sdp__interface.html#ga6e5749a1f05b23675ef9e38b5cb5b32b", null ],
    [ "sdp_sm4_key_bits_t", "group__sdp__interface.html#ga591b507fd9311948ba3c68fbc175dcb2", [
      [ "status_sdp_no_crypto_support", "group__sdp__interface.html#gga85c1893697b201be6423e3534d866636a88a6c197706c3bd6021fa821538fd795", null ],
      [ "status_sdp_no_hash_support", "group__sdp__interface.html#gga85c1893697b201be6423e3534d866636aca714ff069ddf2fb6495c0334b2080e8", null ],
      [ "status_sdp_invalid_key_src", "group__sdp__interface.html#gga85c1893697b201be6423e3534d866636a9a3e2eab48bba0f26a028b1eeff21272", null ],
      [ "status_sdp_error_packet", "group__sdp__interface.html#gga85c1893697b201be6423e3534d866636a07ed2d58378d6363a843612f01fec33b", null ],
      [ "status_sdp_aes_busy", "group__sdp__interface.html#gga85c1893697b201be6423e3534d866636a44d444202b267effd64aae992cd0fc6b", null ],
      [ "status_sdp_hash_busy", "group__sdp__interface.html#gga85c1893697b201be6423e3534d866636ab55a7aad193627315f91f4d84671fbe5", null ],
      [ "status_sdp_error_setup", "group__sdp__interface.html#gga85c1893697b201be6423e3534d866636a2f85949d00d24bd85b8955883dfd234a", null ],
      [ "status_sdp_error_src", "group__sdp__interface.html#gga85c1893697b201be6423e3534d866636a1637f39c05440ad308d9000293625226", null ],
      [ "status_sdp_error_dst", "group__sdp__interface.html#gga85c1893697b201be6423e3534d866636af9f87e1f188c4edbe80bc7d89a2e8ee1", null ],
      [ "status_sdp_error_hash", "group__sdp__interface.html#gga85c1893697b201be6423e3534d866636a4c460f80cfebd73ebc25604caecafe72", null ],
      [ "status_sdp_error_chain", "group__sdp__interface.html#gga85c1893697b201be6423e3534d866636a915d1424baaac4045c3af2079f9d9cfc", null ],
      [ "status_sdp_error_invalid_mac", "group__sdp__interface.html#gga85c1893697b201be6423e3534d866636ac7fcabcafec2fd9b8f01557b0b17156e", null ],
      [ "status_sdp_invalid_alg", "group__sdp__interface.html#gga85c1893697b201be6423e3534d866636a460a1184ebaf7cd2aa9af27f8d1cbbb8", null ]
    ] ],
    [ "sdp_calc_hash_mode_t", "group__sdp__interface.html#ga6a3f07ab3b268e00275f3989817ff106", [
      [ "sdp_calc_hash_for_input", "group__sdp__interface.html#gga6a3f07ab3b268e00275f3989817ff106ae970e0ca3af9c3dbf0fa76d657fffb8a", null ],
      [ "sdp_calc_hash_for_output", "group__sdp__interface.html#gga6a3f07ab3b268e00275f3989817ff106ac678b42051478cd0d9ea57906f6e6b57", null ]
    ] ],
    [ "sdp_crypto_alg_t", "group__sdp__interface.html#ga8dd717546e9adf10bd382a09d655d05c", [
      [ "sdp_crypto_alg_aes", "group__sdp__interface.html#gga8dd717546e9adf10bd382a09d655d05caceeb7f2ed79b74655f2bd875bedf6212", null ]
    ] ],
    [ "sdp_crypto_key_bits_t", "group__sdp__interface.html#ga8df04ef8ae870747d0cf6e72cb9d08a8", [
      [ "sdp_aes_keybits_128", "group__sdp__interface.html#gga8df04ef8ae870747d0cf6e72cb9d08a8aebe4bfb1cda63ea891f5f7579de1af18", null ],
      [ "sdp_aes_keybits_256", "group__sdp__interface.html#gga8df04ef8ae870747d0cf6e72cb9d08a8acc0a0a6b57ff24014bb631875c31258c", null ]
    ] ],
    [ "sdp_crypto_mode_t", "group__sdp__interface.html#ga655532c13e5f26ec7c668266a4152462", [
      [ "sdp_crypto_mode_ecb", "group__sdp__interface.html#gga655532c13e5f26ec7c668266a4152462a8be6bc3cccf0e650523c141a1ddd2cd3", null ],
      [ "sdp_crypto_mode_cbc", "group__sdp__interface.html#gga655532c13e5f26ec7c668266a4152462a00eb0a285a5ce8ff386ec028cddbd646", null ]
    ] ],
    [ "sdp_crypto_op_t", "group__sdp__interface.html#ga7703a60c41664731c2419a25a110ac41", [
      [ "sdp_aes_op_encrypt", "group__sdp__interface.html#gga7703a60c41664731c2419a25a110ac41a3117fa24931bd0cd1d52ea73182749ec", null ],
      [ "sdp_aes_op_decrypt", "group__sdp__interface.html#gga7703a60c41664731c2419a25a110ac41acc4dd81a9bfb05c0533ca744dcb3de37", null ]
    ] ],
    [ "sdp_data_swap_mode_t", "group__sdp__interface.html#ga9c4ff8c44ed7b9bbb94611adbc9bb83f", [
      [ "sdp_swap_mode_none", "group__sdp__interface.html#gga9c4ff8c44ed7b9bbb94611adbc9bb83faaf554776a21a1a2dbf5e8955eaae2df9", null ],
      [ "sdp_swap_mode_bytes_in_word", "group__sdp__interface.html#gga9c4ff8c44ed7b9bbb94611adbc9bb83fa3cb0cdca0e6cb402519017faee698bb9", null ],
      [ "sdp_swap_mode_word_swap", "group__sdp__interface.html#gga9c4ff8c44ed7b9bbb94611adbc9bb83fa22fdba7e78bb4721a97d56a376a5c24b", null ],
      [ "sdp_swap_mode_switch_endian", "group__sdp__interface.html#gga9c4ff8c44ed7b9bbb94611adbc9bb83fa5048835b6308d38d5a5e9493edf5ca7a", null ]
    ] ],
    [ "sdp_hash_alg_t", "group__sdp__interface.html#gaab2a0c515a472eef8c7e5cb4f1d7eee4", [
      [ "sdp_hash_alg_sha1", "group__sdp__interface.html#ggaab2a0c515a472eef8c7e5cb4f1d7eee4a1725eff06fca130610b9b10f13ee7d87", null ],
      [ "sdp_hash_alg_crc32", "group__sdp__interface.html#ggaab2a0c515a472eef8c7e5cb4f1d7eee4a6152490ad2bc6db8a17330037f06c5ba", null ],
      [ "sdp_hash_alg_sha256", "group__sdp__interface.html#ggaab2a0c515a472eef8c7e5cb4f1d7eee4afdf9e228ace7d6319e77350eae0ef609", null ],
      [ "sdp_hash_alg_max", "group__sdp__interface.html#ggaab2a0c515a472eef8c7e5cb4f1d7eee4aa80c1ddacfea8b290f8dd20f79868a6e", null ]
    ] ],
    [ "sdp_operation_t", "group__sdp__interface.html#ga3756a197b58580042efaea0d4c927897", [
      [ "sdp_op_invalid", "group__sdp__interface.html#gga3756a197b58580042efaea0d4c927897ab2326974ee17fdfc480e7f120b7282e9", null ],
      [ "sdp_op_cipher_only", "group__sdp__interface.html#gga3756a197b58580042efaea0d4c927897ac909e029661cee37bd4bffb41184844e", null ],
      [ "sdp_op_hash_only", "group__sdp__interface.html#gga3756a197b58580042efaea0d4c927897afc91056f4a1f900ec02860034ba46c32", null ],
      [ "sdp_op_memcpy_only", "group__sdp__interface.html#gga3756a197b58580042efaea0d4c927897ad7dbc4c5dec56ba982c2a52ee0681d86", null ],
      [ "sdp_op_memfill_only", "group__sdp__interface.html#gga3756a197b58580042efaea0d4c927897a8ffa08fa3021f0fa29d08453cf68b453", null ],
      [ "sdp_op_cipher_hash", "group__sdp__interface.html#gga3756a197b58580042efaea0d4c927897a139cf9c9aa4f54247fe7f8493e6c55ee", null ],
      [ "sdp_op_copy_hash", "group__sdp__interface.html#gga3756a197b58580042efaea0d4c927897abe5aa5a7ebf2ed91286278f09c917357", null ]
    ] ],
    [ "sdp_aes_ccm_decrypt_verify", "group__sdp__interface.html#ga489ecaa21d6ef7959d1c54035f1ab9ae", null ],
    [ "sdp_aes_ccm_generate_encrypt", "group__sdp__interface.html#ga4dfba82c7a94c09311819bc8f1e009df", null ],
    [ "sdp_aes_crypt_cbc", "group__sdp__interface.html#gaf0cc771c288306509b24a650917283a4", null ],
    [ "sdp_aes_crypt_ctr", "group__sdp__interface.html#gade0b1187a0b53baafc71efd07b3995c6", null ],
    [ "sdp_aes_crypt_ecb", "group__sdp__interface.html#gabb01a7313079b4d535fe1fdeb0de76cb", null ],
    [ "sdp_aes_set_key", "group__sdp__interface.html#ga46df53ae0c3e88655999f5e5e398d52a", null ],
    [ "sdp_clear_status", "group__sdp__interface.html#gaf79d47fa8be736b1b9a70b475d6f8b00", null ],
    [ "sdp_deinit", "group__sdp__interface.html#ga4d5276bc1c826ea3dc3ab130836c6afd", null ],
    [ "sdp_disable_interrupt", "group__sdp__interface.html#ga8694c92870a0ff997e427ea703c2c573", null ],
    [ "sdp_enable_interrupt", "group__sdp__interface.html#gadfe1b09c767d64a7c057197fe7309eb6", null ],
    [ "sdp_get_hash_digest", "group__sdp__interface.html#ga5c152bc4bb2c91f80818b5ba2883aa69", null ],
    [ "sdp_get_status", "group__sdp__interface.html#gaac071428ac42d171db72091d9ad0f68e", null ],
    [ "sdp_hash_finish", "group__sdp__interface.html#ga112d4ab7ac0cfba065169b2ef44c49a6", null ],
    [ "sdp_hash_init", "group__sdp__interface.html#gaddc624a4f1b3e898166eb8840ddba5de", null ],
    [ "sdp_hash_update", "group__sdp__interface.html#ga3eca6af1fced0bab36655bd42d237a4a", null ],
    [ "sdp_init", "group__sdp__interface.html#ga4315481c2f0a798f3f55a3547c6f280b", null ],
    [ "sdp_memcpy", "group__sdp__interface.html#ga54cb70aa4500002c9f0d2f98b97ef121", null ],
    [ "sdp_memset", "group__sdp__interface.html#ga6afd14bee029f2a1857529f314cf80b6", null ],
    [ "sdp_set_key_index", "group__sdp__interface.html#ga923359a9d25d9ce04e038801373bb1f3", null ],
    [ "sdp_trigger_action", "group__sdp__interface.html#ga7371a483c2570e98902b168207c10848", null ],
    [ "sdp_wait_done", "group__sdp__interface.html#ga8ef05d86de822df8b6e64e5ca100b2dc", null ],
    [ "sdp_write_cipher_iv", "group__sdp__interface.html#ga470de9e5b50a2aab78ae6777024dea90", null ],
    [ "sdp_write_hash_digest", "group__sdp__interface.html#gad0590d3e4a1d0091659c7ac8ae0c2202", null ],
    [ "sdp_write_key", "group__sdp__interface.html#ga61735d8c8e28ea237b752f0e91202eb0", null ]
];