OUT_DIR = ./build

CMAKE = cmake
MAKE = make
CD = cd
MKDIR = mkdir

stm32f4:
	$(MKDIR) -p $(OUT_DIR)
	$(CD) $(OUT_DIR) && \
	$(CMAKE) .. -DCMAKE_TOOLCHAIN_FILE=../toolchainfiles/stm32f4.cmake -DGRAPHICS_LIB=SSD1306 && \
	$(MAKE)

unix:
	$(MKDIR) -p $(OUT_DIR)
	$(CD) $(OUT_DIR) && \
	$(CMAKE) .. -DCMAKE_TOOLCHAIN_FILE=../toolchainfiles/unix.cmake -DGRAPHICS_LIB=GTK+ && \
	$(MAKE)
