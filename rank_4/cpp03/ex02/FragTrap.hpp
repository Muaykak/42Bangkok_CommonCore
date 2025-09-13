/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:39:49 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 13:49:01 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap( const std::string &name );
		FragTrap( const FragTrap &other );
		FragTrap &operator=( const FragTrap &other );
		~FragTrap();

		void	highFivesGuys( void );
};

#endif 