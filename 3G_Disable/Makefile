TITLE_ID = 	DISABLE3G
TARGET   = 	disable_3g
TITLE    =  3G Disabler
OBJS     = 	main.o font.o graphics.o	

LIBS = -lSceCtrl_stub -lScePower_stub -lSceDisplay_stub -lSceRegistryMgr_stub
	
PREFIX  = arm-vita-eabi
CC      = $(PREFIX)-gcc
CFLAGS  = -Wl,-q -Wall -O3 -std=c99
ASFLAGS = $(CFLAGS)

all: $(TARGET).vpk

%.vpk: eboot.bin
	vita-mksfoex -s TITLE_ID=$(TITLE_ID) "$(TITLE)" param.sfo
	vita-pack-vpk -s param.sfo -b eboot.bin \
		--add sce_sys/icon0.png=sce_sys/icon0.png \
		--add sce_sys/pic0.png=sce_sys/pic0.png \
		--add sce_sys/livearea/contents/bg0.png=sce_sys/livearea/contents/bg0.png \
		--add sce_sys/livearea/contents/default_gate.png=sce_sys/livearea/contents/default_gate.png \
		--add sce_sys/livearea/contents/template.xml=sce_sys/livearea/contents/template.xml \
	$(TARGET).vpk
	
	

eboot.bin: $(TARGET).velf
	vita-make-fself -c $< $@

%.velf: %.elf
	vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

%.o: %.png
	$(PREFIX)-ld -r -b binary -o $@ $^

clean:
	rm -rf $(OBJS) eboot.bin param.sfo $(TARGET).elf $(TARGET).velf $(TARGET).vpk
