# Generator.CPP
Tools to create a an .cpp file from the .hpp

This generator has been create for my personnal use, so it works with my 'norm', in the .hpp, you have to:
- Have the "public:", before the "private:"
- Use private variables start with a '_'
_ Write your getter and setter like : get_var(type) or set_var(type)

exemple :

	public:
		Pony(void);
		~Pony(void);

		std::string		  get_name(void) const;
		int				      set_name(std::string);
		std::string		  get_color(void) const;
		int				      set_color(std::string);
		int				      get_weight(void) const;
		int				      set_weight(int);
		std::string		  get_name_box(void) const;
		int				      set_name_box(std::string);
		int				      test(void);

	private:
		std::string		  _name;
		std::string		  _color;
		int				      _weight;
		std::string		  _name_box;
