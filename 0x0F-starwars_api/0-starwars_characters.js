#!/usr/bin/node
const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`;
function a (person) {
  return new Promise(function (resolve, reject) {
    request(person, function (e, r, b) {
      if (e) reject(e);
      resolve(JSON.parse(b).name);
    });
  });
}

request(url, async function (error, response, body) {
  if (error) console.log(error);
  const films = JSON.parse(body);
  for (let idx = 0; idx < films.characters.length; idx++) {
    console.log(await a(films.characters[idx]));
  }
});
