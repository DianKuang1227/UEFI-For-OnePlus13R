  FILE FREEFORM = EB98F32B-F211-48B6-B9E2-D6B4F6E6D7E9 {
    SECTION UI = "SecParti.cfg"
    SECTION RAW = Binaries/giulia/RawFiles/SecParti.cfg
  }

!if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
  FILE FREEFORM = 04AC6223-3702-47EF-9223-413D225365D0 {
    SECTION UI = "Panel_AA577_P_3_A0020_dsc_cmd.xml"
    SECTION RAW = Binaries/giulia/RawFiles/Panel_AA577_P_3_A0020_dsc_cmd.xml
  }
!endif

  FILE FREEFORM = 605AB4ED-2C7F-40C6-A0C0-E558E8D50BE6 {
    SECTION UI = "uefipil.cfg"
    SECTION RAW = Binaries/giulia/RawFiles/uefipil.cfg
  }

  FILE FREEFORM = 6381460E-31F8-41C8-8F14-ACB33C35A417 {
    SECTION UI = "QcomChargerCfg.cfg"
    SECTION RAW = Binaries/giulia/RawFiles/QcomChargerCfg.cfg
  }
