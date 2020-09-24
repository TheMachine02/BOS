
define bos? bos
namespace bos
;
;DONOTHING                       := $20108
;DONOTHING                       := $2010C
;DONOTHING                       := $20110
;DONOTHING                       := $20114
;DONOTHING                       := $20118
;DONOTHING                       := $2011C
?sys_ExecuteFile                 := $20120
?sys_ExecuteFileEntryPoint       := $20124
?fs_OpenFile                     := $20128
?fs_GetSectorPtr                 := $2012C
?fs_CheckDirExists               := $20130
?fs_GetPathLastName              := $20134
;
?LCD_PAL    := 0E30200h
?LCD_CTRL   := 0E30018h
?LCD_VRAM   := 0D40000h
?LCD_BUFFER := LCD_VRAM + LCD_WIDTH*LCD_HEIGHT
?LCD_WIDTH  := 320
?LCD_HEIGHT := 240
?LCD_8BPP   := $27
?LCD_16BPP  := $2D
?TEXT_MAX_ROW    := 231
?RAM_START  := 0D00400h
?flags.sys_flags              := -1
?flags.lcd_bg_color           :=  0
?flags.text_fg                :=  1
?flags.text_bg                :=  2
?flags.color_primary          :=  3
?flags.font_spacing           :=  4
?flags.font_data              :=  7
?flags.lcd_x                  :=  10
?flags.lcd_y                  :=  13
?flags.free_RAM_ptr           :=  16
?flags.remaining_free_RAM     :=  19
?flags.free_VAT_entry_ptr     :=  22
?flags.cursor_x               :=  25
?flags.cursor_y               :=  28
?flags.cursor_flags           :=  29
?flags.lcd_text_fg            :=  30
?flags.lcd_text_bg            :=  31
?flags.cursor_color           :=  32
?flags.free_file_RAM_ptr      :=  33
?flags.remaining_file_RAM     :=  36
?flags.console_line           :=  39
?bos_read_only_fs        := 1
?cursor_2nd              := 1
?flag_start             := $D00000
?lcd_bg_color           := $D00080
?text_fg                := $D00081
?text_bg                := $D00082
?color_primary          := $D00083
?font_spacing           := $D00084
?font_data              := $D00087
?lcd_x                  := $D0008A
?lcd_y                  := $D0008D
?free_RAM_ptr           := $D00090
?remaining_free_RAM     := $D00093
?free_VAT_entry_ptr     := $D00096
?lcd_text_fg            := $D00097
?lcd_text_bg            := $D00098
?cursor_color           := $D00099
?free_file_RAM_ptr      := $D000A0
?remaining_file_RAM     := $D000A3
?console_line           := $D000A6
?ScrapMem2              := $D000F9
?ScrapByte              := $D000FC
?ScrapWord              := $D000FD
?ScrapMem               := $D000FD
?open_files_table       := $D00100
?InputBuffer            := $D00200
?gfx_string_temp        := $D00300
?current_working_dir    := $D00310
?fsOP1                  := $D00500
?fsOP2                  := $D00510
?fsOP3                  := $D00520
?fsOP4                  := $D00530
?fsOP5                  := $D00540
?fsOP6                  := $D00550
?current_cluster_map    := $D00580
?stackbot               := $D08000
?start_of_file_RAM      := $D10000
?end_of_file_RAM        := $D40000
?total_file_RAM         := end_of_file_RAM-start_of_file_RAM
?start_of_user_archive  := $0C0000 ;sector $0C, standard
?end_of_user_archive    := $3B0000 ;sector $3B, start of certificate

end namespace