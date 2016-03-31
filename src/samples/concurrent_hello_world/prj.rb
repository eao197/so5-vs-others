require 'mxx_ru/cpp'

MxxRu::Cpp::exe_target {

	required_prj 'so_5/prj.rb'
	target 'concurrent_hello_world'

	cpp_source 'main.cpp'
}
