Bulnes_MapScripts::
    map_script MAP_SCRIPT_ON_RESUME, Route101_OnResume
    .byte 0

Route101_OnResume:
    setstepcallback STEP_CB_ASH
    end

