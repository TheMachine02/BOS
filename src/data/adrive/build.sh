mkdir obj
fasmg src/main.asm obj/main.bin
convbin -i obj/main.bin -o data.bin -j bin -k bin -c zx7
read -p "Finished. Press enter to continue."