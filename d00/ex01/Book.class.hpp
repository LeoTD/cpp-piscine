#ifndef BOOK_CLASS_HPP
# define BOOK_CLASS_HPP

# include "Entry.class.hpp"
# include <string>

class Book {
	private:
		Entry		*_entry;
		int			_nbr_entries;

	public:
		Book();
		~Book();

		void				add_entry(void);
		void				search(void);
		void				print_entries(void);
		void				__printf_full_entry(int);
};

#endif