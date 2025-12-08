/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 23:42:11 by srussame          #+#    #+#             */
/*   Updated: 2025/11/29 21:02:48 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	jimmy;

	jimmy.complain("DEBUG");
	jimmy.complain("INFO");
	jimmy.complain("WARNING");
	jimmy.complain("ERROR");
	// jimmy doesn't calm
	jimmy.complain("CALM");
}