/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:35:02 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 20:11:16 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"


Brain::Brain(){
	std::cout << "Brain Default Constructor Called" << std::endl;

	this->ideas[0] = "A subscription box for rare international snacks.";
    this->ideas[1] = "An AI-powered app that generates personalized study plans.";
    this->ideas[2] = "A platform for renting out specialized tools and equipment to neighbors.";
    this->ideas[3] = "A service that creates personalized, guided meditation scripts.";
    this->ideas[4] = "Smart glasses that offer real-time language translation.";
    this->ideas[5] = "An app that generates recipes based on ingredients you have at home.";
    this->ideas[6] = "A decentralized social network focused on local community events.";
    this->ideas[7] = "A sustainable fashion brand using recycled materials.";
    this->ideas[8] = "A website that helps people find and join niche hobby clubs.";
    this->ideas[9] = "An automated plant care system for urban gardeners.";
    this->ideas[10] = "A service that designs custom-made pet furniture.";
    this->ideas[11] = "An online course platform for learning 'lost' practical skills like weaving or blacksmithing.";
    this->ideas[12] = "A marketplace for buying and selling rare collectibles.";
    this->ideas[13] = "An app that tracks and analyzes your spending habits to find savings.";
    this->ideas[14] = "A peer-to-peer network for exchanging digital art and music.";
    this->ideas[15] = "A smart home device that monitors air quality and suggests improvements.";
    this->ideas[16] = "A service that connects travelers with local, non-touristy experiences.";
    this->ideas[17] = "A mobile game where you build and manage a fantasy kingdom.";
    this->ideas[18] = "An app for managing small-scale charity fundraising events.";
    this->ideas[19] = "A company that creates custom ergonomic desk setups.";
    
    // Creative & Art
    this->ideas[20] = "Write a sci-fi short story about a forgotten lunar colony.";
    this->ideas[21] = "Compose a musical piece based on the sound of a rainstorm.";
    this->ideas[22] = "Create a graphic novel about a sentient city.";
    this->ideas[23] = "Develop a board game where players build an intergalactic trade empire.";
    this->ideas[24] = "Learn to paint with watercolors and focus on landscapes.";
    this->ideas[25] = "Start a podcast that explores the history of mythology.";
    this->ideas[26] = "Design and build your own custom computer keyboard.";
    this->ideas[27] = "Write a series of poems inspired by different emotions.";
    this->ideas[28] = "Choreograph a dance piece that tells a story without words.";
    this->ideas[29] = "Create a photo series documenting forgotten historical landmarks.";
    this->ideas[30] = "Build a miniature model of a famous fictional building.";
    this->ideas[31] = "Create a short animated film using stop-motion.";
    this->ideas[32] = "Start a blog that critiques and analyzes classic films.";
    this->ideas[33] = "Craft handmade leather goods like wallets or bags.";
    this->ideas[34] = "Design a series of minimalist posters for classic books.";
    this->ideas[35] = "Learn the art of calligraphy and hand-lettering.";
    this->ideas[36] = "Write a children's book about a friendly monster.";
    this->ideas[37] = "Record a series of acoustic covers of your favorite songs.";
    this->ideas[38] = "Develop a unique style of abstract art using unconventional tools.";
    this->ideas[39] = "Design and sew your own custom clothing.";
    
    // Personal Growth & Life Hacks
    this->ideas[40] = "Start a 30-day challenge to learn a new skill.";
    this->ideas[41] = "Create a 'memory jar' to store positive moments throughout the year.";
    this->ideas[42] = "Learn basic car maintenance to save money on repairs.";
    this->ideas[43] = "Volunteer for a cause you're passionate about.";
    this->ideas[44] = "Practice mindful breathing for 10 minutes every morning.";
    this->ideas[45] = "Plan a weekend trip to a nearby town you've never visited.";
    this->ideas[46] = "Read one classic novel every month.";
    this->ideas[47] = "Declutter your living space using the KonMari method.";
    this->ideas[48] = "Journal for five minutes a day to clear your mind.";
    this->ideas[49] = "Learn to cook one new, complex meal each week.";
    this->ideas[50] = "Start a strength training routine at the gym or at home.";
    this->ideas[51] = "Master the art of public speaking through Toastmasters.";
    this->ideas[52] = "Learn a new language using a free app like Duolingo.";
    this->ideas[53] = "Develop a morning routine that includes exercise and healthy eating.";
    this->ideas[54] = "Learn how to budget and invest your money.";
    this->ideas[55] = "Practice gratitude by writing down three things you're thankful for daily.";
    this->ideas[56] = "Organize a community event like a park cleanup or potluck.";
    this->ideas[57] = "Take a digital detox weekend to unplug and recharge.";
    this->ideas[58] = "Start a personal garden with your favorite vegetables.";
    this->ideas[59] = "Learn to play a musical instrument, like the guitar or piano.";

    // Education & Learning
    this->ideas[60] = "Study the history of a specific ancient civilization.";
    this->ideas[61] = "Learn the fundamentals of coding in Python.";
    this->ideas[62] = "Take an online course on quantum physics for beginners.";
    this->ideas[63] = "Master a specific style of cooking, like French cuisine or baking.";
    this->ideas[64] = "Research and write a paper on a controversial historical event.";
    this->ideas[65] = "Learn the basics of investing and personal finance.";
    this->ideas[66] = "Study the fundamentals of astronomy and planetary science.";
    this->ideas[67] = "Learn to speak a new language, like Japanese or Spanish.";
    this->ideas[68] = "Take up a new hobby that requires manual dexterity, like knitting or model building.";
    this->ideas[69] = "Study the history and principles of different philosophical schools of thought.";

    // Travel & Adventure
    this->ideas[70] = "Plan and execute a solo backpacking trip.";
    this->ideas[71] = "Visit all the national parks in your country.";
    this->ideas[72] = "Learn to surf at a coastal destination.";
    this->ideas[73] = "Hike a famous trail, like the Appalachian Trail or the Pacific Crest Trail.";
    this->ideas[74] = "Travel to a new country and try to only speak the local language.";
    this->ideas[75] = "Plan a road trip to a unique geological landmark.";
    this->ideas[76] = "Go on a safari and learn about wildlife conservation.";
    this->ideas[77] = "Visit every state in your country.";
    this->ideas[78] = "Learn to sail a small boat.";
    this->ideas[79] = "Explore a different cultural festival in a nearby city each year.";
    
    // Miscellaneous
    this->ideas[80] = "Learn to mix and create unique cocktails.";
    this->ideas[81] = "Start a YouTube channel about your favorite hobby.";
    this->ideas[82] = "Build a miniature computer or a robot.";
    this->ideas[83] = "Learn basic survival skills, like building a fire or finding clean water.";
    this->ideas[84] = "Organize and host a trivia night for your friends.";
    this->ideas[85] = "Build a simple web page or app.";
    this->ideas[86] = "Write a letter to your future self to be opened in 10 years.";
    this->ideas[87] = "Try a new type of exercise, like yoga or rock climbing.";
    this->ideas[88] = "Learn the basics of photography and take a photo every day for a month.";
    this->ideas[89] = "Start a collection of something unique, like antique maps or vintage coins.";
    this->ideas[90] = "Volunteer at an animal shelter or local charity.";
    this->ideas[91] = "Create a custom playlist of your favorite songs for every mood.";
    this->ideas[92] = "Learn to play chess or another strategic board game.";
    this->ideas[93] = "Organize your digital files and photos.";
    this->ideas[94] = "Learn basic first aid and CPR.";
    this->ideas[95] = "Create a scrapbook of your family history.";
    this->ideas[96] = "Learn to make your own bread from scratch.";
    this->ideas[97] = "Start a book club with friends.";
    this->ideas[98] = "Create a custom comic book of your life.";
    this->ideas[99] = "Learn a magic trick to impress your friends and family.";
}

Brain::Brain( const Brain &other ){
	std::cout << "Brain Copy Constructor Called" << std::endl;
	this->operator=(other);
}

Brain &Brain::operator=( const Brain &other ){
	std::cout << "Brain Copy Assignment Operator Called" << std::endl;
	for (unsigned int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain(){
	std::cout << "Brain Destructor Called" << std::endl;
}

