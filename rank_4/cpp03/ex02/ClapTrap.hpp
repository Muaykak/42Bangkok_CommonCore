/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 02:10:21 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 14:19:58 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{
	private:
		std::string	_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:
		ClapTrap();
		ClapTrap( const std::string &new_name);
		ClapTrap( const ClapTrap &other );
		ClapTrap &operator=(const ClapTrap &other);
		virtual ~ClapTrap();

		std::string		getName( void ) const ;
		unsigned int	getHP( void ) const ;
		unsigned int	getEnergy( void ) const ;
		unsigned int	getAtkDmg( void ) const ;
		void			setName( const std::string &new_name );
		void			setHP( unsigned int new_hp );
		void			setEnergy( unsigned int new_eneygy );
		void			setAtkDmg( unsigned int new_atk_dmg );

		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	
};

#endif