require('dotenv').config();
const app = require('./server');

require('./database/index');

async function main()
{
    await app.listen(app.get('port'));

    console.log(`Server on port: ${app.get('port')}`);
}

main();