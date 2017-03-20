const SerialPort = require('serialport');
const botToken = require('./secret/bot-token');
const TelegramBot = require('node-telegram-bot-api');
const port = new SerialPort('/dev/cu.SLAB_USBtoUART', {
      baudRate: 115200
});
const bot = new TelegramBot(botToken, {polling: true});

bot.on('message', (msg) => console.log(msg));

port.on('data', function (data) {
    console.log('Data: ' + data);
    bot.sendMessage('192296003', data);
});
