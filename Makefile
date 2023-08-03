CC = gcc
OUT = build/main.out

default:
	@clear
	@echo Building project...
	@$(CC) src/*.c src/app/*.c -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_ttf.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_ttf -o $(OUT)
	@echo Project executable is now ready! 

run:
	@clear
	@echo Running project...
	@$(OUT)
	@echo Execution has ended!

clean:
	@echo Cleaning build directory...
	@rm -f $(OUT)
	@echo Build directory is empty
