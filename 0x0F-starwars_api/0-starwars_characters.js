#!/usr/bin/node
// script that prints all characters of a Star Wars movie via star wars api
const request = require('request');
const process = require('process');

// need to encorporate "in the same order as the “characters” list in the /films/ endpoint"
request.get('https://swapi-api.hbtn.io/api/films/' + process.argv[2] + '/', function (err, response, body) {
  if (err) {
    console.log(err);
  }

  const characters = JSON.parse(body).characters;
  const orderedChars = {};

  const whole = JSON.parse(body);
  for (const char of whole.characters) {
    request.get(char, function (err, res, body) {
      const wholeChars = JSON.parse(body);
      if (err) {
        console.log(err);
      } else {
        const characterName = wholeChars.name;
        orderedChars[char] = characterName;
      }
      if (Object.values(orderedChars).length === characters.length) {
        characters.forEach(character => {
          console.log(orderedChars[character]);
        });
      }
    });
  }
});
