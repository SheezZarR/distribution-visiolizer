rebuild:
	rm -rf build
	cmake -S . -B build
	ln -fs build/compile_commands.json ./compile_commands.json
