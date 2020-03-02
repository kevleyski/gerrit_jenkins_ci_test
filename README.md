# gerrit_jenkins_ci_test
This is Kev testing GitHub with Jenkins and Gerrit code review

![C/C++ CI](https://github.com/kevleyski/gerrit_jenkins_ci_test/workflows/C/C++%20CI/badge.svg)

How to set it up...

Register Gerrit as a Github OAuth application
login to Github
open the URL: https://github.com/settings/applications/new
Application name: Gerrit
Homepage URL: https://review.my-domain.org
Authorization callback URL: https://review.my-domain.org/oauth
Note: Client ID & Client Secret are generated that used in the next step.

Running Gerrit init to configure GitHub OAuth
java -jar buck-out/gen/gerrit.war $gerrit_site

User Authentication

Authentication methodi []: HTTP

Ger username from custom HTTP header [Y/n]? Y

Username HTTP header []: GITHUB_USER

SSO logout URL : /oauth/reset

GitHub Integration

GitHub URL: [https://github.com]:

Use GitHub for Gerrit login? [Y/n] Y

ClientId []:

ClientSecret []:

Receiving Pull Request events to automatically import
Create a github user account which automatic import operation uses.
Register the account to your gerrit site by logging into Gerrit with the account.
Create webhook on your github repository.
The payload URL should be something like http://your-gerrit-host.example/plugins/github-plugin-version/webhook.
It is recommended to specify some webhook secret.
Edit etc/gerrit.config and etc/secure.config files in your $gerrit_site.
Add the github user account name as webhookUser entry in github section of etc/gerrit.config
Add the webhook secret as webhookSecret entry in github section of etc/secure.config.
