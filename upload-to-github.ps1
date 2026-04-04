#!/usr/bin/env pwsh
# GitHub Upload Script for Mechanical Keyboard Project
# This script automates uploading your keyboard firmware to GitHub

Write-Host "=== Mechanical Keyboard - GitHub Upload ===" -ForegroundColor Cyan
Write-Host ""

# Check if git is installed
if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
    Write-Host "ERROR: Git is not installed!" -ForegroundColor Red
    Write-Host "Please install Git from https://git-scm.com/download/win" -ForegroundColor Yellow
    exit 1
}

# Get GitHub username
Write-Host "Enter your GitHub username: " -NoNewline -ForegroundColor Cyan
$username = Read-Host
if ([string]::IsNullOrWhiteSpace($username)) {
    Write-Host "ERROR: GitHub username is required" -ForegroundColor Red
    exit 1
}

# Get repository name
Write-Host "Enter repository name (default: mechanical-keyboard-pico): " -NoNewline -ForegroundColor Cyan
$repoName = Read-Host
if ([string]::IsNullOrWhiteSpace($repoName)) {
    $repoName = "mechanical-keyboard-pico"
}

Write-Host ""
Write-Host "Repository URL will be: https://github.com/$username/$repoName" -ForegroundColor Yellow
Write-Host ""
Write-Host "Before continuing, you must:" -ForegroundColor Cyan
Write-Host "1. Create a GitHub account at https://github.com/signup" -ForegroundColor White
Write-Host "2. Create a new repository at https://github.com/new" -ForegroundColor White
Write-Host "   - Name: $repoName" -ForegroundColor White
Write-Host "3. Create a Personal Access Token at https://github.com/settings/tokens" -ForegroundColor White
Write-Host "   - Check 'repo' and 'workflow' boxes" -ForegroundColor White
Write-Host ""
Write-Host "Press Enter to continue or Ctrl+C to cancel..." -ForegroundColor Cyan
Read-Host

# Add remote
Write-Host "Setting up git remote..." -ForegroundColor Green
git remote remove origin 2>$null
git remote add origin "https://github.com/$username/$repoName.git"
if ($LASTEXITCODE -ne 0) {
    Write-Host "ERROR: Failed to add git remote" -ForegroundColor Red
    exit 1
}

# Rename branch to main
Write-Host "Setting up main branch..." -ForegroundColor Green
git branch -M main 2>$null

# Push to GitHub
Write-Host "Pushing to GitHub (you will be prompted for credentials)..." -ForegroundColor Green
Write-Host "Use your GitHub username and Personal Access Token (not your password)" -ForegroundColor Yellow
Write-Host ""
git push -u origin main

if ($LASTEXITCODE -eq 0) {
    Write-Host ""
    Write-Host "=== SUCCESS ===" -ForegroundColor Green
    Write-Host "Your project has been uploaded to GitHub!" -ForegroundColor Green
    Write-Host ""
    Write-Host "View your project at:" -ForegroundColor Cyan
    Write-Host "https://github.com/$username/$repoName" -ForegroundColor Yellow
    Write-Host ""
    Write-Host "Next steps:" -ForegroundColor Cyan
    Write-Host "1. Visit the GitHub repository link above" -ForegroundColor White
    Write-Host "2. Go to images folder" -ForegroundColor White
    Write-Host "3. Upload your build photos" -ForegroundColor White
    Write-Host "4. Share the link with others!" -ForegroundColor White
} else {
    Write-Host ""
    Write-Host "=== ERROR ===" -ForegroundColor Red
    Write-Host "Failed to push to GitHub. Check your credentials and repository setup." -ForegroundColor Red
}
