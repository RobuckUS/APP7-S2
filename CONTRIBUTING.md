# Contribute to APP7-S2

This is a reminder of some useful commands to collaborate on this project.

### Get a copy of the code

Clone the repository via `HTTPS`

    git clone https://github.com/RobuckUS/APP7-S2.git

or via `SSH`

    git clone git@github.com:RobuckUS/APP7-S2.git

### Before you start working on a new feature

You should create a new branch (`featureName` in the example) based on the latest commit of `master`.

    git checkout master
    git pull
    git checkout -b featureName

### Integrate change from `master`

If you want to integrate change from `master` into `yourBranch`

    git checkout yourBranch
    git merge master

### Commit your change and send them to GitHub

Before making a commit, you should check what it will change so you don't commit stuff you don't want.

    git diff          //To check change before file are added
    git add <file>
    git diff --cached //To check change in the next commit
    git reset <file>  //To undo git add

Then commit with a one-line messages for a small change, or, for bigger changes, something like this:

    git commit -m "A brief summary of the commit
     
    A paragraph describing what changed and its impact."

Then, you should push your changes to GitHub.

    git push

### Merge changes to `master`

When you are ready to merge the feature to master, send a [GitHub Pull Request to RobuckUS](https://github.com/RobuckUS/APP7-S2/pull/new/master) with a clear list of what you've done and **ask someone to review your changes**.
