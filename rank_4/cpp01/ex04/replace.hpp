/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:07:03 by srussame          #+#    #+#             */
/*   Updated: 2025/09/09 23:31:08 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>

# ifndef OUTFILE_NAME
#  define OUTFILE_NAME "outfile"
# endif 

bool	replace( std::ifstream &infile, std::ofstream &outfile,
			const std::string &s1, const std::string &s2);

#endif