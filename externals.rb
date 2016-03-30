gem 'Mxx_ru', '>= 1.6.8'
require 'mxx_ru/externals'

MxxRu::git_externals :so5 do |e|
	e.url 'https://github.com/eao197/so-5-5.git'
	e.tag 'v5.5.16'
	e.map_dir 'dev/so_5' => 'src'
	e.map_dir 'dev/timertt' => 'src'
end
