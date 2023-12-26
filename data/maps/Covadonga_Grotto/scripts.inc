Covadonga_Grotto_MapScripts::
	.byte 0


TESTE_EventScript_Pokeball::
	lockall
	showmonpic SPECIES_RAYQUAZA, 10, 3
	msgbox TESTE_EventScript_Pokeball_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq TESTE_EventScript_Pokeball_2
	hidemonpic
	msgbox TESTE_NotChosen
TESTE_EventScript_Pokeball_1:
	waitmessage
	releaseall
	end

TESTE_EventScript_Pokeball_2:
	givemon SPECIES_RAYQUAZA, 80, ITEM_MASTER_BALL
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TESTE_EventScript_Pokeball_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TESTE_EventScript_Pokeball_6
	hidemonpic
	msgbox TESTE_EventScript_Pokeball_Text_2
	goto TESTE_EventScript_Pokeball_1

TESTE_EventScript_Pokeball_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox TESTE_EventScript_Pokeball_Text_1
	removeobject 16
	setflag FLAG_UNUSED_0x493
	call NicknamePartyMon
	goto TESTE_EventScript_Pokeball_1

TESTE_EventScript_Pokeball_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox TESTE_EventScript_Pokeball_Text_1
	removeobject 16
	setflag FLAG_UNUSED_0x493
	call NicknameBoxMon
	goto TESTE_EventScript_Pokeball_1


NicknamePartyMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
	call Common_EventScript_TransferredToPC
	return

NicknameBoxMon_2:
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


Covadonga_Grotto_Sign01::
	lockall
	msgbox Covadonga_Grotto_Sign01_Text_0
	releaseall
	return


TESTE_EventScript_Pokeball_Text_0:
	.string "Do you want to choose Rayquaza?$"

TESTE_EventScript_Pokeball_Text_1:
	.string "Recieved Rayquaza$"

TESTE_EventScript_Pokeball_Text_2:
	.string "No More Room$"

NicknamePartyMon_Text_0:
	.string "Give it a nickname?$"

Covadonga_Grotto_Sign01_Text_0:
	.string "TESTANDO ESSE NEGÓCIO MALUCO QUE\n"
	.string "COISA CHATA E INSUPORTAVEL, GOSTARIA\l"
	.string "DE COMER O CUZINHO DAS PUTA TUDO$"

TESTE_NotChosen::
	.string "You did not choose the Pokemon$"
