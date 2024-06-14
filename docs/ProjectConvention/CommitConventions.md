# Commit conventions
[Home](../ReadMe.md) 

## What does this file represent

this file present a commit conventions for project

## Reference

1. [Commit Structure](#commit-structure)

2. [Commit Flags](#commit-flags)

## Commit structure 
[Return](#reference)

    <Flags for commits>: Optional header
    -- Commits content

this standard accepts the use of different flags in one commit if needed example at the bottom
## Example

    <Feature>
    -- Created a new button for main layout

    <Docs>
    -- Created a documentation for new button class

    <Cmake>
    -- Configured cmake for new button file

    <Ui>
    -- A new style has been created for the button in menu

## Commit flags

what is the commit flag
commit flags are responsible for present the content of the commit e.g. you have added a new feature use the feature flag to notify the reader what has been added in this particular commit and when you change the documentation use the docs flag etc

### Types for commit flags

    <Refactor>
    Code is refactored and not added feature

    <Feature>
    New Feature added

    <Build>
    Any change in files such as changing the path of the files

    <Docs>
    Change in documentation

    <Cmake>
    Some change in cmake type new file added or something changed in old

    <NonCritBugFix>
    Fixed a non-critical bug

    <CritBugFix>
    Fixed a critical bug

    <Ui>
    Ui related changes

    <Other>
    This flag is used when something is not included in the flags or change is a special event e.x change in clang-format file

[Return](../ReadMe.md)